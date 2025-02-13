#include <gtest.h>
#include "polinome.h"

TEST(Degree, can_create_default) {
	ASSERT_NO_THROW(Monom<int>::Degree());
}
TEST(Degree, default_create_null) {
	Monom<int>::Degree deg;
	ASSERT_EQ(deg.get(), 0);
}
TEST(Degree, can_create) {
	ASSERT_NO_THROW(Monom<int>::Degree(96));
}
TEST(Degree, correct_create) {
	Monom<int>::Degree deg(96);
	ASSERT_EQ(deg.get(), 96);
}
TEST(Degree, cant_create_GE_1000) {
	ASSERT_ANY_THROW(Monom<int>::Degree(1000));
}
TEST(Degree, can_operator_ravno) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(69);
	ASSERT_NO_THROW(a == b);
	ASSERT_NO_THROW(a == a);
}
TEST(Degree, operator_ravno_ravno) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(96);
	ASSERT_EQ(a == b, true);
}
TEST(Degree, operator_ravno_neravno) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(69);
	ASSERT_NE(a == b, true);
}
TEST(Degree, can_operator_neravno) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(69);
	ASSERT_NO_THROW(a != b);
	ASSERT_NO_THROW(a != a);
}
TEST(Degree, operator_neravno_ravno) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(96);
	ASSERT_NE(a != b, true);
}
TEST(Degree, operator_neravno_neravno) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(69);
	ASSERT_EQ(a != b, true);
}
TEST(Degree, can_copy_constr) {
	Monom<int>::Degree a(96);
	ASSERT_NO_THROW(Monom<int>::Degree b = a);
}
TEST(Degree, correct_copy_constr) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b = a;
	ASSERT_EQ(a, b);
}
TEST(Degree, operator_LE_L) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(69);
	ASSERT_EQ(b <= a, true);
}
TEST(Degree, operator_LE_R) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(69);
	ASSERT_NE(a <= b, true);
}
TEST(Degree, operator_LE_E) {
	Monom<int>::Degree a(96);
	ASSERT_EQ(a <= a, true);
}
TEST(Degree, operator_RE_L) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(69);
	ASSERT_NE(b >= a, true);
}
TEST(Degree, operator_RE_R) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(69);
	ASSERT_EQ(a >= b, true);
}
TEST(Degree, operator_RE_E) {
	Monom<int>::Degree a(96);
	ASSERT_EQ(a >= a, true);
}
TEST(Degree, operator_R_L) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(69);
	ASSERT_NE(b > a, true);
}
TEST(Degree, operator_R_R) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(69);
	ASSERT_EQ(a > b, true);
}
TEST(Degree, operator_L_L) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(69);
	ASSERT_EQ(b < a, true);
}
TEST(Degree, operator_L_R) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(69);
	ASSERT_NE(a < b, true);
}
TEST(Degree, can_operator_plus) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(69);
	ASSERT_NO_THROW(a + b);
}
TEST(Degree, correct_operator_plus) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(69);
	Monom<int>::Degree c(96 + 69);
	ASSERT_EQ(a + b, c);
}
TEST(Degree, cant_operator_plus_too_big) {
	Monom<int>::Degree a(999);
	Monom<int>::Degree b(1);
	ASSERT_ANY_THROW(a + b);
}
TEST(Degree, can_operator_minus) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(69);
	ASSERT_NO_THROW(a - b);
}
TEST(Degree, correct_operator_minus) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(69);
	Monom<int>::Degree c(96 - 69);
	ASSERT_EQ(a - b, c);
}
TEST(Degree, cant_operator_minus) {
	Monom<int>::Degree a(2);
	Monom<int>::Degree b(1);
	ASSERT_ANY_THROW(b-a);
}
TEST(Degree, can_operator_mult) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(3);
	ASSERT_NO_THROW(a * b);
}
TEST(Degree, correct_operator_mult) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(3);
	Monom<int>::Degree c(96 * 3);
	ASSERT_EQ(a * b, c);
}
TEST(Degree, cant_operator_mult) {
	Monom<int>::Degree a(500);
	Monom<int>::Degree b(2);
	ASSERT_ANY_THROW(b * a);
}
TEST(Degree, can_operator_div) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(3);
	ASSERT_NO_THROW(a / b);
}
TEST(Degree, cant_operator_div_drob) {
	Monom<int>::Degree a(97);
	Monom<int>::Degree b(3);
	ASSERT_ANY_THROW(a / b);
}
TEST(Degree, correct_operator_div) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(3);
	Monom<int>::Degree c(96 / 3);
	ASSERT_EQ(a / b, c);
}
TEST(Degree, can_copy) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b;
	ASSERT_NO_THROW(b = a);
}
TEST(Degree, correct_copy) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b;
	b = a;
	ASSERT_EQ(a, b);
}
TEST(Degree, correct_copy_self) {
	Monom<int>::Degree a(96);
	Monom<int>::Degree b(96);
	a = a;
	ASSERT_EQ(a, b);
}
TEST(Degree, can_get) {
	Monom<int>::Degree a(963);
	ASSERT_NO_THROW(a.get());
}
TEST(Degree, correct_get) {
	Monom<int>::Degree a(963);
	ASSERT_EQ(a.get(), 963);
}
TEST(Degree, can_getX) {
	Monom<int>::Degree a(963);
	ASSERT_NO_THROW(a.getX());
}
TEST(Degree, correct_getX) {
	Monom<int>::Degree a(963);
	ASSERT_EQ(a.getX(), 9);
}
TEST(Degree, can_getY) {
	Monom<int>::Degree a(963);
	ASSERT_NO_THROW(a.getY());
}
TEST(Degree, correct_getY) {
	Monom<int>::Degree a(963);
	ASSERT_EQ(a.getY(), 6);
}
TEST(Degree, can_getZ) {
	Monom<int>::Degree a(963);
	ASSERT_NO_THROW(a.getZ());
}
TEST(Degree, correct_getZ) {
	Monom<int>::Degree a(963);
	ASSERT_EQ(a.getZ(), 3);
}
TEST(Degree, can_set) {
	Monom<int>::Degree a(43);
	ASSERT_NO_THROW(a.set(32));
}
TEST(Degree, cant_set_big) {
	Monom<int>::Degree a(43);
	ASSERT_ANY_THROW(a.set(1000));
}
TEST(Degree, correct_set) {
	Monom<int>::Degree a(43);
	a.set(354);
	ASSERT_EQ(a.get(),354);
}
TEST(Degree, can_setX) {
	Monom<int>::Degree a(43);
	ASSERT_NO_THROW(a.setX(2));
}
TEST(Degree, cant_set_bigX) {
	Monom<int>::Degree a(43);
	ASSERT_ANY_THROW(a.setX(10));
}
TEST(Degree, correct_setX) {
	Monom<int>::Degree a(43);
	a.setX(3);
	ASSERT_EQ(a.get(), 343);
}
TEST(Degree, can_setY) {
	Monom<int>::Degree a(43);
	ASSERT_NO_THROW(a.setY(2));
}
TEST(Degree, cant_set_bigY) {
	Monom<int>::Degree a(43);
	ASSERT_ANY_THROW(a.setY(10));
}
TEST(Degree, correct_setY) {
	Monom<int>::Degree a(43);
	a.setY(6);
	ASSERT_EQ(a.get(), 63);
}
TEST(Degree, can_setZ) {
	Monom<int>::Degree a(43);
	ASSERT_NO_THROW(a.setZ(2));
}
TEST(Degree, cant_set_bigZ) {
	Monom<int>::Degree a(43);
	ASSERT_ANY_THROW(a.setZ(10));
}
TEST(Degree, correct_setZ) {
	Monom<int>::Degree a(43);
	a.setZ(7);
	ASSERT_EQ(a.get(), 47);
}
TEST(Degree, can_add) {
	Monom<int>::Degree a(1);
	ASSERT_NO_THROW(a.add(998));
}
TEST(Degree, cant_add_big) {
	Monom<int>::Degree a(1);
	ASSERT_ANY_THROW(a.add(999));
}
TEST(Degree, correct_add) {
	Monom<int>::Degree a(23);
	a.add(65);
	Monom<int>::Degree b(23+65);
	ASSERT_EQ(a, b);
}
TEST(Degree, can_addX) {
	Monom<int>::Degree a(1);
	ASSERT_NO_THROW(a.addX(5));
}
TEST(Degree, cant_add_big_X) {
	Monom<int>::Degree a(400);
	ASSERT_ANY_THROW(a.addX(7));
}
TEST(Degree, cant_add_bigX) {
	Monom<int>::Degree a(1);
	ASSERT_ANY_THROW(a.addX(10));
}
TEST(Degree, correct_addX) {
	Monom<int>::Degree a(23);
	a.addX(6);
	Monom<int>::Degree b(623);
	ASSERT_EQ(a, b);
}
TEST(Degree, can_addY) {
	Monom<int>::Degree a(110);
	ASSERT_NO_THROW(a.addY(5));
}
TEST(Degree, cant_add_big_Y) {
	Monom<int>::Degree a(440);
	ASSERT_ANY_THROW(a.addY(7));
}
TEST(Degree, cant_add_bigY) {
	Monom<int>::Degree a(1);
	ASSERT_ANY_THROW(a.addY(10));
}
TEST(Degree, correct_addY) {
	Monom<int>::Degree a(23);
	a.addY(6);
	Monom<int>::Degree b(83);
	ASSERT_EQ(a, b);
}
TEST(Degree, can_addZ) {
	Monom<int>::Degree a(110);
	ASSERT_NO_THROW(a.addY(5));
}
TEST(Degree, cant_add_big_Z) {
	Monom<int>::Degree a(444);
	ASSERT_ANY_THROW(a.addY(7));
}
TEST(Degree, cant_add_bigZ) {
	Monom<int>::Degree a(10);
	ASSERT_ANY_THROW(a.addZ(10));
}
TEST(Degree, correct_addZ) {
	Monom<int>::Degree a(23);
	a.addZ(6);
	Monom<int>::Degree b(29);
	ASSERT_EQ(a, b);
}
/////////у лукоморь€ дуб зеленый, злата€ цепь на дубе том, и днем и ночью кот ученый сидит считает полином...
TEST(Monom, default_constr) {
	ASSERT_NO_THROW(Monom<int> a());
}
TEST(Monom, default_constr_right_degree) {
	Monom<int> a = Monom<int>();
	ASSERT_EQ(a.DEGREE.get(),0);
}
TEST(Monom, default_constr_right_const) {
	Monom<int> a = Monom<int>();
	ASSERT_EQ(a.value(), 0);
}
TEST(Monom, constr_c) {
	ASSERT_NO_THROW(Monom<int> a(52));
}
TEST(Monom, constr_c_deg) {
	Monom<int> a(52);
	ASSERT_EQ(a.DEGREE.get(), 0);
}
TEST(Monom, constr_c_right_const) {
	Monom<int> a(52);
	ASSERT_EQ(a.value(), 52);
}
TEST(Monom, constr_c_d) {
	ASSERT_NO_THROW(Monom<int> a(52,127));
}
TEST(Monom, constr_c_d_deg) {
	Monom<int> a(52,127);
	ASSERT_EQ(a.DEGREE.get(), 127);
}
TEST(Monom, constr_c_d_right_const) {
	Monom<int> a(52,127);
	ASSERT_EQ(a.value(), 52);
}
TEST(Monom, operator_LE_l) {
	Monom<int> a(12, 432);
	Monom<int> b(54, 231);
	ASSERT_EQ(b <= a, true);
}
TEST(Monom, operator_LE_r) {
	Monom<int> a(12, 432);
	Monom<int> b(54, 231);
	ASSERT_NE(a <= b, true);
}
TEST(Monom, operator_LE_e) {
	Monom<int> a(12, 432);
	Monom<int> b(54, 231);
	ASSERT_EQ(a <= a, true);
}
TEST(Monom, operator_RE_l) {
	Monom<int> a(12, 432);
	Monom<int> b(54, 231);
	ASSERT_NE(b >= a, true);
}
TEST(Monom, operator_RE_r) {
	Monom<int> a(12, 432);
	Monom<int> b(54, 231);
	ASSERT_EQ(a >= b, true);
}
TEST(Monom, operator_RE_e) {
	Monom<int> a(12, 432);
	Monom<int> b(54, 231);
	ASSERT_EQ(a >= a, true);
}
TEST(Monom, operator_r_l) {
	Monom<int> a(12, 432);
	Monom<int> b(54, 231);
	ASSERT_NE(b > a, true);
}
TEST(Monom, operator_r_r) {
	Monom<int> a(12, 432);
	Monom<int> b(54, 231);
	ASSERT_EQ(a >= b, true);
}
TEST(Monom, operator_l_l) {
	Monom<int> a(12, 432);
	Monom<int> b(54, 231);
	ASSERT_EQ(b < a, true);
}
TEST(Monom, operator_l_r) {
	Monom<int> a(12, 432);
	Monom<int> b(54, 231);
	ASSERT_NE(a < b, true);
}
TEST(Monom, operator_ravno_ravno) {
	Monom<int> a(12, 432);
	Monom<int> b(54, 432);
	ASSERT_EQ(a == b, true);
}
TEST(Monom, operator_ravno_neravno) {
	Monom<int> a(12, 432);
	Monom<int> b(54, 431);
	ASSERT_NE(a == b, true);
}
TEST(Monom, operator_neravno_ravno) {
	Monom<int> a(12, 432);
	Monom<int> b(54, 432);
	ASSERT_NE(a != b, true);
}
TEST(Monom, operator_neravno_neravno) {
	Monom<int> a(12, 432);
	Monom<int> b(54, 431);
	ASSERT_EQ(a != b, true);
}
TEST(Monom, isNull) {
	Monom<int> a(0, 224);
	ASSERT_EQ(a.isNull(), true);
}
TEST(Monom, ravno_ravno) {
	Monom<int> a(12, 432);
	Monom<int> b(12, 432);
	ASSERT_EQ(a.EQ(b), true);
}
TEST(Monom, ravno_neravno_1) {
	Monom<int> a(12, 432);
	Monom<int> b(54, 432);
	ASSERT_NE(a.EQ(b), true);
}
TEST(Monom, ravno_neravno_2) {
	Monom<int> a(12, 432);
	Monom<int> b(12, 431);
	ASSERT_NE(a.EQ(b), true);
}
TEST(Monom, neravno_ravno) {
	Monom<int> a(12, 432);
	Monom<int> b(12, 432);
	ASSERT_NE(a.NE(b), true);
}
TEST(Monom, neravno_neravno_1) {
	Monom<int> a(12, 432);
	Monom<int> b(54, 432);
	ASSERT_EQ(a.NE(b), true);
}
TEST(Monom, neravno_neravno_2) {
	Monom<int> a(12, 432);
	Monom<int> b(12, 431);
	ASSERT_EQ(a.NE(b), true);
}
TEST(Monom, GR_cant_dif_deg) {
	Monom<int> a(12, 432);
	Monom<int> b(12, 431);
	ASSERT_ANY_THROW(a.GR(b));
}
TEST(Monom, LO_cant_dif_deg) {
	Monom<int> a(12, 432);
	Monom<int> b(12, 431);
	ASSERT_ANY_THROW(a.LO(b));
}
TEST(Monom, GE_cant_dif_deg) {
	Monom<int> a(12, 432);
	Monom<int> b(12, 431);
	ASSERT_ANY_THROW(a.GE(b));
}
TEST(Monom, LE_cant_dif_deg) {
	Monom<int> a(12, 432);
	Monom<int> b(12, 431);
	ASSERT_ANY_THROW(a.LE(b));
}
TEST(Monom, LE_l) {
	Monom<int> a(432, 32);
	Monom<int> b(231, 32);
	ASSERT_EQ(b.LE(a), true);
}
TEST(Monom, LE_r) {
	Monom<int> a(432, 32);
	Monom<int> b(231, 32);
	ASSERT_NE(a.LE(b), true);
}
TEST(Monom, LE_e) {
	Monom<int> a(432, 32);
	Monom<int> b(231, 32);
	ASSERT_EQ(a.LE(a), true);
}
TEST(Monom, RE_l) {
	Monom<int> a(432, 32);
	Monom<int> b(231, 32);
	ASSERT_NE(b.GE(a), true);
}
TEST(Monom, RE_r) {
	Monom<int> a(432, 32);
	Monom<int> b(231, 32);
	ASSERT_EQ(a.GE(b), true);
}
TEST(Monom, RE_e) {
	Monom<int> a(432, 32);
	Monom<int> b(231, 32);
	ASSERT_EQ(a.GE(a), true);
}
TEST(Monom, r_l) {
	Monom<int> a(432, 32);
	Monom<int> b(231, 32);
	ASSERT_NE(b.GR(a), true);
}
TEST(Monom, r_r) {
	Monom<int> a(432, 32);
	Monom<int> b(231, 32);
	ASSERT_EQ(a.GR(b), true);
}
TEST(Monom, l_l) {
	Monom<int> a(432, 32);
	Monom<int> b(231, 32);
	ASSERT_EQ(b.LO(a), true);
}
TEST(Monom, l_r) {
	Monom<int> a(432, 32);
	Monom<int> b(231, 32);
	ASSERT_NE(a.LO(b), true);
}
TEST(Monom, valueAdd) {
	Monom<int> a(432, 32);
	a.valueAdd(12432);
	ASSERT_EQ(432 + 12432, a.value());
}
TEST(Monom, valueSet) {
	Monom<int> a(432, 32);
	a.valueSet(12432);
	ASSERT_EQ(12432, a.value());
}
TEST(Monom, operator_plus_cant_dif_deg) {
	Monom<int> a(432, 313);
	Monom<int> b(231, 32);
	ASSERT_ANY_THROW(a + b);
}
TEST(Monom, operator_minus_cant_dif_deg) {
	Monom<int> a(432, 313);
	Monom<int> b(231, 32);
	ASSERT_ANY_THROW(a - b);
}
TEST(Monom, operator_plus) {
	Monom<int> a(432, 32);
	Monom<int> b(231, 32);
	Monom<int> c = a+b;
	auto d = c.DEGREE.get();
	auto co = c.value();
	ASSERT_EQ(d, 32);
	ASSERT_EQ(co, 432+231);
}
TEST(Monom, operator_minus) {
	Monom<int> a(432, 32);
	Monom<int> b(231, 32);
	Monom<int> c = a - b;
	auto d = c.DEGREE.get();
	auto co = c.value();
	ASSERT_EQ(d, 32);
	ASSERT_EQ(co, 432 - 231);
}
TEST(Monom, operator_mult) {
	Monom<int> a(432, 32);
	Monom<int> b(231, 162);
	Monom<int> c = a * b;
	auto d = c.DEGREE.get();
	auto co = c.value();
	ASSERT_EQ(d, 194);
	ASSERT_EQ(co, 432 * 231);
}
TEST(Monom, operator_mult_cant_big_deg) {
	Monom<int> a(432, 42);
	Monom<int> b(231, 162);
	ASSERT_ANY_THROW(Monom<int> c = a * b);
}
TEST(Monom, operator_mult_const) {
	Monom<int> a(432, 42);
	auto c = a * 76;
	auto d = c.DEGREE.get();
	auto co = c.value();
	ASSERT_EQ(d, 42);
	ASSERT_EQ(co, 432 * 76);
}
TEST(Monom, operator_div_const) {
	Monom<int> a(432, 42);
	auto c = a / 76;	//int!!!!
	auto d = c.DEGREE.get();
	auto co = c.value();
	ASSERT_EQ(d, 42);
	ASSERT_EQ(co, 432 / 76);
}
TEST(Monom, copy) {
	Monom<int> a(432, 42),b(32,43);
	b = a;
	auto d = a.DEGREE.get(), h = b.DEGREE.get();
	ASSERT_EQ(d, h);
	auto t = a.value(), y = b.value();
	ASSERT_EQ(t, y);
}
TEST(Monom, copy_own_mem) {
	Monom<int> a(432, 42), b(32, 43);
	b = a;
	auto d = a.DEGREE.get(), h = b.DEGREE.get();
	ASSERT_EQ(d, h);
	auto t = a.value(), y = b.value();
	ASSERT_EQ(t, y);
	a.DEGREE.set(228);
	auto g = a.DEGREE.get(), l = b.DEGREE.get();
	ASSERT_NE(g, l);
}
//ћороз и солнце, день чудесный! » полином такой прелестный! ѕора, мономушка, сложись....
TEST(Polinome, default_constructor) {
	ASSERT_NO_THROW(Polinome<int> a = Polinome<int>());
}
TEST(Polinome, constructor_monom) {
	Monom<int> aa(23, 104);
	ASSERT_NO_THROW(Polinome<int> a(aa));
}
TEST(Polinome, constructor_monom_) {
	Monom<int> aa(23, 104);
	Polinome<int> a(aa);
	ASSERT_EQ(a.begin(), a.last());
	ASSERT_EQ((*(a.begin())).DEGREE.get(), aa.DEGREE.get());
	ASSERT_EQ((*(a.begin())).value(), aa.value());
}
TEST(Polinome, constrct_list_consts) {
	List<int> e = { 1,2,3,4,5,6 };
	Polinome<int> d(e);
	int de = 0;
	auto it2 = e.begin();
	for (auto it = d.begin();; ++it) {
		ASSERT_EQ((*it).DEGREE.get(), ++de);
		ASSERT_EQ((*it).value(), *it2);
		if (it == d.last())break;
		++it2;
	}
}
TEST(Polinome, cnstrct_copy) {
	List<int> e = { 1,2,3,4,5,6 };
	Polinome<int> d(e);
	Polinome<int> a = d;
	for (auto it1 = d.begin(), it2 = a.begin();; ++it1, ++it2) {
		ASSERT_EQ((*it1).DEGREE.get(), (*it2).DEGREE.get());
		ASSERT_EQ((*it1).value(), (*it2).value());
		if (it1 == d.last())break;
	}
}
TEST(Polinome, cnstrct_sz) {
	Polinome<int> d(10);
	ASSERT_EQ(d.getList().size(), 10);
}
TEST(Polinome, size) {
	List<int> a = { 1,2,3,4,5 };
	Polinome<int> b(a);
	ASSERT_EQ(b.size(), a.size());
}
TEST(Polinome, clear) {
	List<int> a = { 1,2,3,4,5 }, b = {};
	Polinome<int> c(a), d(b);
	c.clear();
	ASSERT_EQ(c.getList(), d.getList());
}
TEST(Polinome, SORT) {
	List<int> a = { 1,6,3,7,0,54 }, b = a;
	b.merge_sort();
	Polinome<int> c(a), d(b);
	c.SORT();
	ASSERT_EQ(c.getList(), d.getList());
}
TEST(Polinome, check_sorted) {
	List<Monom<int>> a;
	Monom<int> g(21, 32);
	a.push_back(g);
	g = Monom<int>(21, 20);
	a.push_back(g);
	g = Monom<int>(21, 40);
	a.push_back(g);
	Polinome<int> b(a);
	ASSERT_NE(b.check_sorted(), true);
	b.SORT();
	ASSERT_EQ(b.check_sorted(), true);
}
TEST(Polinome, push_back_size) {
	Polinome<int> a = List<int>({1,2,3,4,5});
	a.push_back(2);
	ASSERT_EQ(a.size(), 6);
}
TEST(Polinome, push_back_) {
	Polinome<int> a = List<int>({ 1,2,3,4,5 });
	List<int> t1 = { 1,2,3,4,5,2 };
	a.push_back(2);
	ASSERT_EQ((*a.last()).value(), 2);
}
TEST(Polinome,operator_copy) {
	List<int> e = { 1,2,3,4,5,6 };
	Polinome<int> d(e);
	Polinome<int> a;
	a = d;
	for (auto it1 = d.begin(), it2 = a.begin();; ++it1, ++it2) {
		ASSERT_EQ((*it1).DEGREE.get(), (*it2).DEGREE.get());
		ASSERT_EQ((*it1).value(), (*it2).value());
		if (it1 == d.last())break;
	}
}
TEST(Polinome, operator_mul) {
	List<Monom<int>> a;
	Monom<int> g(21, 32);
	a.push_back(g);
	g = Monom<int>(-21, 20);
	a.push_back(g);
	g = Monom<int>(21, 40);
	a.push_back(g);
	Polinome<int> b(a);
	a.clear();
	Polinome<int> c = b * b;
	g = Monom<int>(441, 80);
	a.push_back(g);
	g=Monom<int>(882, 72);
	a.push_back(g);
	g=Monom<int>(441, 64);
	a.push_back(g);
	g=Monom<int>(-882, 60);
	a.push_back(g);
	g=Monom<int>(-882, 52);
	a.push_back(g);
	g=Monom<int>(441, 40);
	a.push_back(g);
	Polinome<int> l(a);
	l.SORT();
	ASSERT_EQ(l, c);
}
TEST(Polinome, operator_mul_c) {
	List<Monom<int>> a;
	Monom<int> g(21, 32);
	a.push_back(g);
	g = Monom<int>(-21, 20);
	a.push_back(g);
	g = Monom<int>(21, 40);
	a.push_back(g);
	Polinome<int> b(a);
	a.clear();
	Polinome<int> c = b * 2323;
	List<Monom<int>> a1;
	Monom<int> g1(21*2323, 32);
	a1.push_back(g1);
	g1 = Monom<int>(-21*2323, 20);
	a1.push_back(g1);
	g1 = Monom<int>(21*2323, 40);
	a1.push_back(g1);
	Polinome<int> b1(a1);
	ASSERT_EQ(c, b1);
}
TEST(Polinome, operator_plus) {
	List<Monom<int>> a;
	Monom<int> g(21, 32);
	a.push_back(g);
	g = Monom<int>(-21, 20);
	a.push_back(g);
	g = Monom<int>(21, 40);
	a.push_back(g);
	Polinome<int> b(a);
	auto g1 = b * 2;
	g1.SORT();
	b.SORT();
	Polinome<int> c = b + b;
	ASSERT_EQ(g1, c);
}
TEST(Polinome, cant_operator_plus_non_sort) {
	List<Monom<int>> a;
	Monom<int> g(21, 32);
	a.push_back(g);
	g = Monom<int>(-21, 20);
	a.push_back(g);
	g = Monom<int>(21, 40);
	a.push_back(g);
	Polinome<int> b(a);
	ASSERT_ANY_THROW(b + b);
}
TEST(Polinome, operator_minus) {
	List<Monom<int>> a;
	Monom<int> g(21, 32);
	a.push_back(g);
	g = Monom<int>(-21, 20);
	a.push_back(g);
	g = Monom<int>(21, 40);
	a.push_back(g);
	Polinome<int> b(a);
	b.SORT();
	Polinome<int> c = b - b;
	b.clear();
	ASSERT_EQ(b, c);
}
TEST(Polinome, cant_operator_minus_non_sort) {
	List<Monom<int>> a;
	Monom<int> g(21, 32);
	a.push_back(g);
	g = Monom<int>(-21, 20);
	a.push_back(g);
	g = Monom<int>(21, 40);
	a.push_back(g);
	Polinome<int> b(a);
	ASSERT_ANY_THROW(b - b);
}