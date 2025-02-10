#pragma once
#include <string>
#include "list.h"
#include "parse_digits.h"

struct psevdo_lexem {
	short type;
	std::string name;
	psevdo_lexem() :type(0), name("") {};
	psevdo_lexem(short t, const std::string& s) :type(t), name(s) {};
	
};
std::ostream& operator<<(std::ostream& os, psevdo_lexem& pl) {
	std::cout << pl.name;
	return os;
}
//type:
// 0 - undefined
// 1 - +/-
// 2 - Const
// 3 - variable
// 4 - degree

template <typename T>
struct Monom {
	class Degree {
		size_t degree;
	public:
		Degree(size_t deg = 0) :degree(deg) {}
		Degree(const Degree& deg) :degree(deg.degree) {};
		~Degree() {}
		bool operator<=(const Degree& right_) { return degree <= right_.degree; }
		bool operator<(const Degree& right_) { return degree < right_.degree; }
		bool operator>(const Degree& right_) { return degree > right_.degree; }
		bool operator>=(const Degree& right_) { return degree >= right_.degree; }
		bool operator==(const Degree& right_) { return degree == right_.degree; }
		bool operator!=(const Degree& right_) { return degree != right_.degree; }

		Degree operator+(const Degree& right_) { if (degree + right_.degree > 999) throw std::length_error("TO BIG DEGREE"); return Degree(degree + right_.degree); }
		Degree operator-(const Degree& right_) { if (degree + right_.degree > 999) throw std::length_error("INCORRECT DEGREE"); return Degree(degree - right_.degree); }
		Degree operator*(const Degree& right_) { if (degree + right_.degree > 999) throw std::length_error("INCORRECT DEGREE"); return Degree(degree * right_.degree); }
		Degree operator/(const Degree& right_) { if (degree + right_.degree > 999 || (degree < right_.degree) || (degree % right_.degree != 0)) throw std::length_error("INCORRECT DEGREE"); return Degree(degree * right_.degree); }

		size_t get()const noexcept{ return degree; }
		size_t getX() const noexcept { return degree / 100; }
		size_t getY() const noexcept { return (degree - (degree / 100)*100) / 10; }
		size_t getZ() const noexcept { return degree % 10; }

		void set(size_t deg) { if (deg > 999)throw std::length_error("TO BIG DEGREE"); degree = deg; }
		void setX(size_t deg) { if (deg > 9 || ((degree - degree / 100) + deg * 100) > 999)throw std::length_error("TO BIG DEGREEE"); degree = ((degree - degree / 100) + deg * 100); }
		void setY(size_t deg) { if (deg > 9 || ((degree - ((degree - (degree / 100)*100) / 10)) + deg * 10) > 999)throw std::length_error("TO BIG DEGREE"); degree = ((degree - ((degree - degree / 100) / 10)) + deg * 10); }
		void setZ(size_t deg) { if (deg > 9 || ((degree - degree % 10) + deg) > 999)throw std::length_error("TO BIG DEGREE"); degree = ((degree - degree % 10) + deg); }

		void add(size_t deg) { operator+(deg); }
		void addX(size_t deg) { operator+(deg * 100); }
		void addY(size_t deg) { operator+(deg * 10); }
		void addZ(size_t deg) { operator+(deg); }
	};

	Degree DEGREE;

	Monom() :DEGREE(000), C(T()) {}
	Monom(const T& c_) : C(c_), DEGREE(000) {};
	Monom(const T& c_, const Degree& deg) : C(c_), DEGREE(deg) {};
	~Monom() {}
	//!ONLY DEGREE CMP OPERATORS!
	bool operator<=(const Monom& right_) { return DEGREE <= right_.DEGREE; }
	bool operator<(const Monom& right_) { return DEGREE < right_.DEGREE; }
	bool operator>(const Monom& right_) { return DEGREE > right_.DEGREE; }
	bool operator>=(const Monom& right_) { return DEGREE >= right_.DEGREE; }
	bool operator==(const Monom& right_) { return DEGREE == right_.DEGREE; }
	bool operator!=(const Monom& right_) { return DEGREE != right_.DEGREE; }

	bool isNull() { return C == T(0); }
	bool EQ(const Monom& right_) { return C == right_.C && DEGREE == right_.DEGREE; }	//==
	bool NE(const Monom& right_) { return C != right_.C || DEGREE != right_.DEGREE; }	//!=
	bool GR(const Monom& right_) { if (DEGREE != right_.DEGREE) throw std::logic_error("different degree!"); return C > right_.C; }	//>
	bool LO(const Monom& right_) { if (DEGREE != right_.DEGREE) throw std::logic_error("different degree!"); return C < right_.C; }	//<
	bool GE(const Monom& right_) { if (DEGREE != right_.DEGREE) throw std::logic_error("different degree!"); return C >= right_.C; }	//>=
	bool LE(const Monom& right_) { if (DEGREE != right_.DEGREE) throw std::logic_error("different degree!"); return C <= right_.C; }	//<=

	T value() const noexcept { return C; }
	void valueAdd(const T& right_) { C = C + right_; }
	void valueSet(const T& right_) { C = right_; }

	Monom operator+(const Monom& right_) {
		if (DEGREE != right_.DEGREE) throw std::logic_error("different degree!");
		return Monom(C + right_.C, DEGREE);
	}
	Monom operator-(const Monom& right_) {
		if (DEGREE != right_.DEGREE) throw std::logic_error("different degree!");
		return Monom(C - right_.C, DEGREE);
	}
	Monom operator*(const Monom& right_) {
		if (DEGREE != right_.DEGREE) throw std::logic_error("different degree!");
		return Monom(C * right_.C, DEGREE);
	}
	Monom operator/(const Monom& right_) {
		if (DEGREE != right_.DEGREE) throw std::logic_error("different degree!");
		return Monom(C / right_.C, DEGREE);
	}
	friend std::ostream& operator<<(std::ostream& os, const Monom<T>& right_) {
		if (right_.value() != T(0)) {
			os << abs(right_.value());
			size_t X = right_.DEGREE.getX(), Y = right_.DEGREE.getY(), Z = right_.DEGREE.getZ();
			if (X) os << "X";
			if (X != 1 && X) os << X;
			if (Y) os << "Y";
			if (Y != 1 && Y) os << Y;
			if (Z) os << "Z";
			if (Z != 1 && Z) os << Z;
			os << ' ';
		}
		return os;
	}

private:
	T C;
};

#define _dig(a) ((a)>=48 && (a)<=57)
#define vars(a) (((a)=='X' || (a)=='Y' || (a)=='Z')||((a)=='x' || (a)=='y' || (a)=='z'))
#define oper(a) ((a)=='+' || (a)=='-')
#define allow(a) (oper(a) || _dig(a) || vars(a) || (a)==' ' || (a)=='.' || (a)=='e' || (a)=='E')

bool check_allow_main_symb(const std::string& s) {	//check all nums or vars in string
	for (const auto& el : s) {
		if (!_dig(el) && !vars(el)) return 0;
	}
	return 1;
}

bool all_Nums(const std::string& s) {	//check all nums in string
	for (const auto& el : s) {
		if (!_dig(el)) return 0;
	}
	return 1;
}

template <typename val_>
class Polinome {
private:
	List<Monom<val_>> polinome;
public:
	Polinome() : polinome(Monom<val_>()) {};
	Polinome(const Monom<val_>& right_) : polinome(right_) {};
	Polinome(const Polinome<val_>& right_) : polinome(right_.polinome) {};
	Polinome(const List<Monom<val_>>& right_) : polinome(right_) {}
	Polinome(const List<val_>& right_) : polinome(){
		size_t sz = 0;
		for (auto it = right_.begin();; ++it) {
			polinome.push_back(Monom<val_>(*it,++sz));
			if (it == right_.last()) break;
		}
	}
	Polinome(const size_t& sz) : polinome(sz, val_(0)) {};
	~Polinome() {};

	Iterator_L<Monom<val_>> begin() const {
		return polinome.begin();
	}
	Iterator_L<Monom<val_>> last() const {
		return polinome.last();
	}

	const List<Monom<val_>>& getList()const {
		return polinome;
	}
	size_t size() const { return polinome.size(); }

	void clear() { polinome.clear(); }

	void SORT() { polinome.merge_sort(); }

	bool check_sorted() const{ return polinome.check_sorted(); }

	void push_back(const Monom<val_>& right_) { polinome.push_back(right_); }

	Polinome operator+(const Polinome& right_) {
		if (!check_sorted() || !right_.check_sorted()) throw j_error("Polinoms must be sorted for +");
		
		auto it1 = begin();
		auto it2 = right_.begin();
		Polinome<val_> res(0);
		auto null_ = val_(0);
		bool f1 = true, f2 = true;
		while (true) {

			if (*it1 == *it2) {
				if (!(abs(((*it1).value() + (*it2).value()) - null_) <= numeric_limits<val_>::epsilon())) {
					res.push_back(Monom<val_>((*it1).value() + (*it2).value(), (*it1).DEGREE.get()));
				}
				if (it1 == last() || it2 == right_.last())break;
				++it1;
				++it2;
				
			}
			else if (*it1 < *it2) {
				res.push_back(*it1);
				if (it1 == last())break;
				++it1;
			}
			else {
				res.push_back(*it2);
				if (it2 == right_.last())break;
				++it2;
			}
			
		}
		if(it1!=last())
		while (true) {
			res.push_back(*it1);
			if (it1 == last())break;
			++it1;
		}
		if (it2 != right_.last())
			while (true) {
				res.push_back(*it2);
				if (it2 == right_.last())break;
				++it2;
			}
		/*if (res.size() == 0) {
			res.push_back(Monom<val_>(0));
		}*/
		return res;
	}

	friend std::ostream& operator<<(std::ostream& os, const Polinome<val_>& p) {
		size_t lgth = 0;
		if (p.size() == 0) {
			os << 0;
			return os;
		}
		for (auto it = p.begin();; ++it) {
			auto right_Monom = *it;
			if (lgth) os << ((right_Monom.value() > val_(0)) ? ("+ ") : ((right_Monom.value() < val_(0)) ? "- " : ""));
			++lgth;
			
			os << right_Monom;
			if (it == p.last()) break;
		}
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Polinome<val_>& p) {
		std::string raw_input;
		is >> std::ws;
		getline(is, raw_input);
		for (auto i = 0; i < raw_input.size(); i++) if (!allow(raw_input.at(i))) throw j_error("Incorrect symbol '" + std::string(1,raw_input[i]) + "' in position " + my_to_String(i));
		const size_t n = raw_input.size();
		vector<std::string> prepare;
		for (size_t i = 0; i < n; i++) {
			if (raw_input[i] == ' ') continue;
			if (_dig(raw_input[i])) {
				std::string temp = "";
				while (i < n && !vars(raw_input[i]) && !oper(raw_input[i]) && raw_input[i] != ' ') {
					temp += raw_input[i];
					++i;
				}
				prepare.push_back(temp);
				if (i >= n)break;
				--i;
			}
			else if (raw_input[i] == '+' || raw_input[i] == '-') prepare.push_back((raw_input[i]=='+' ? "+" : "-"));
			else {
				std::string temp = "";
				while (i < n && !oper(raw_input[i]) && raw_input[i] != ' ') {
					temp += raw_input[i];
					++i;
				}
				prepare.push_back(temp);
				if (i >= n)break;
				--i;
			}
		}
		//�� ���� ������� prepare ������������ ����� ������ � ������������ ������� � ������������ �� ��� ����� �������� - ��������� � ���������� �� ���������
		vector<psevdo_lexem> post;
		bool f = 1;
		for (auto lex : prepare) {
			if (f && lex.at(0) != '-') { post.push_back({ 1,"+" }); }
			f = 0;
			if (lex.size() == 1 && oper(lex.at(0))) {
				post.push_back({ 1,lex });
			}
			else if (all_Nums(lex)) {
				post.push_back({ 2, lex });
			}
			else {
				if (!vars(lex.at(0))) throw j_error("expected variable in the beginning of the '"+lex+"'");
				bool x = 0, y = 0, z = 0;
				if (!check_allow_main_symb(lex)) throw j_error("Incorrect symbols in '" + lex+"'");
				for (auto i = 0; i < lex.size(); i++) {
					
					if (lex[i] == 'X' || lex[i] == 'x') {
						if (x) throw j_error("More than one X in '" + lex + "'");
						++i; ++x;
						std::string degree = "";
						while (i < lex.size() && _dig(lex.at(i))) degree += lex.at(i++);
						--i;
						post.push_back({ 3,"X"});
						post.push_back({4,degree});
						if (degree == "")post.back().name = "1";
					}else if (lex[i] == 'Y' || lex[i] == 'y') {
						if (y) throw j_error("More than one Y in '" + lex + "'");
						++i; ++y;
						std::string degree = "";
						while (i < lex.size() && _dig(lex.at(i))) degree += lex.at(i++);
						--i;
						post.push_back({ 3,"Y" });
						post.push_back({ 4,degree });
						if (degree == "") post.back().name = "1";
					}
					else if (lex[i] == 'Z' || lex[i] == 'z') {
						if (z) throw j_error("More than one Z in '" + lex + "'");
						++i; ++z;
						std::string degree = "";
						while (i < lex.size() && _dig(lex.at(i))) degree += lex.at(i++);
						--i;
						post.push_back({ 3,"Z" });
						post.push_back({ 4,degree });
						if (degree == "")post.back().name = "1";
					}
					
				}
			}
		}
		//������ post ����� ���������� ���������� �� �����, �����, ����������, �������
		//�������� ������ - ������ �� ��� ����� � ������ ���� - ���� +
		vector<Monom<val_>> psevdPolinom;
		for (auto i = 0; i < post.size(); i++) {

			size_t degreE = 0;
			bool pos = 1;
			val_ Co;
			if (post.at(i).type != 1) throw j_error("Incorrect symbol in '" + post[i].name + "'");
			if (post.at(i).name == "-") pos = 0;
			
			++i;
			Co = parser(post.at(i).name);
			if (!pos) Co = -Co;
			++i;
			
			for (int j = 0; j < 3; j++) {
				if (i == post.size()) break;
				if (post.at(i).name == "X") {
					++i;
					degreE += parser(post.at(i).name) * 100;
					++i;
				}
				if (i == post.size())break;
				if (post.at(i).name == "Y") {
					++i;
					degreE += parser(post.at(i).name) * 10;
					++i;
				}
				if (i == post.size())break;
				if (post.at(i).name == "Z") {
					++i;
					degreE += parser(post.at(i).name);
					++i;
				}
				if (i == post.size() || oper(post.at(i).name.at(0)))break;
			}
			--i;
			psevdPolinom.push_back({ Co, degreE });
		}
		size_t sz1 = p.size();
		if (sz1 != psevdPolinom.size()) throw j_error("Polinome and input must have equal size!");
		sz1 = 0;;
		for (auto it = p.begin();; ++it) {
			*it = psevdPolinom.at(sz1++);
			if (it == p.last()) break;
		}
		p.SORT();
		return is;
	}
};