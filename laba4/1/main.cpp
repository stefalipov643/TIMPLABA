#include "modAlpha.cpp"
#include "modAlpha.h"

#include <UnitTest++/UnitTest++.h>
#include <locale>
using namespace std;
SUITE(KeyTest)
{
    TEST(ValidKey) { 
    wstring t1 = L"ЭХЙРТЧНЧЮ";
    wstring t2 = modAlphaCipher(L"НЕБО").encrypt(L"ПРИВЕТМИР");
    if (t1==t2) {
    CHECK(true);
    }
    else {
    CHECK(false);
    }
    }
    
    TEST(LongKey) { 
    wstring t3 = L"ЯБНМХТ";
    wstring t4 = modAlphaCipher(L"ПРЕКРАСНАЯПОГОДА").encrypt(L"ПРИВЕТ");
    if (t3==t4) {
    CHECK(true);
    }
    else {
    CHECK(false);
    }
    }
    
    TEST(LowCaseKey) { 
    wstring t5 = L"ЭХЙРТЧНЧЮ";
    wstring t6 = modAlphaCipher(L"небо").encrypt(L"ПРИВЕТМИР");
    if (t5==t6) {
    CHECK(true);
    }
    else {
    CHECK(false);
    }
    }
    TEST(DigitsInKey) { 
    CHECK_THROW(modAlphaCipher cp(L"Б1"), cipher_error);}
    
    TEST(PunctuationInKey) { 
    CHECK_THROW(modAlphaCipher cp(L"Б,С"), cipher_error); }
    
    TEST(WhitespaceInKey) 
    { CHECK_THROW(modAlphaCipher cp(L"Б С"), cipher_error); }
    
    TEST(EmptyKey) 
    { CHECK_THROW(modAlphaCipher cp(L""), cipher_error); }
    
    TEST(WeakKey) 
    { CHECK_THROW(modAlphaCipher cp(L"ААА"), cipher_error); }
}
//класс, который в конструкторе создает динамический экземпляр шифратора с ключом «B», а в
//деструкторе — уничтожает
struct KeyB_fixture {
    modAlphaCipher* p;
    KeyB_fixture() 
    { p = new modAlphaCipher(L"Б");
    }
    ~KeyB_fixture() 
    {delete p; 
    }
};

SUITE(EncryptTest)
{
 TEST_FIXTURE(KeyB_fixture, UpCaseString){
 wstring t7 = L"ВЁМЬКТОЁДРФЩЙТУЬКГГПИЕФЦЁЛСФЗЙУТА";
 wstring t8 = p->encrypt(L"БЕЛЫЙСНЕГПУШИСТЫЙВВОЗДУХЕКРУЖИТСЯ");
 if (t7==t8) {
 CHECK(true);
 }
 else {
 CHECK(false);
 } 
 }
 
 TEST_FIXTURE(KeyB_fixture, LowCaseString){
 wstring t9 = L"ВЁМЬКТОЁДРФЩЙТУЬКГГПИЕФЦЁЛСФЗЙУТА";
 wstring t10 = p->encrypt(L"белыйснегпушистыйввоздухекружится");
 if (t9==t10) {
 CHECK(true);
 }
 else {
 CHECK(false);
 } 
 }
 
 TEST_FIXTURE(KeyB_fixture, StringWithWhitspaceAndPunct){
 wstring t11 = L"ВЁМЬКТОЁДРФЩЙТУЬКГГПИЕФЦЁЛСФЗЙУТА";
 wstring t12 = p->encrypt(L"БЕЛЫЙ СНЕГ, ПУШИСТЫЙ В ВОЗДУХЕ КРУЖИТСЯ");
 if (t11==t12) {
 CHECK(true);
 }
 else {
 CHECK(false);
 }
 }
 
 TEST_FIXTURE(KeyB_fixture, StringWithNumbers){
 wstring t13 = L"ТОПГЬНДПЕПН";
 wstring t14 = p->encrypt(L"С Новым 2025 Годом");
 if (t13==t14) {
 CHECK(true);
 }
 else {
 CHECK(false);
 }
 }
 
 TEST_FIXTURE(KeyB_fixture, EmptyString) {
 CHECK_THROW(p->encrypt(L""),cipher_error);
 }
 
 TEST_FIXTURE(KeyB_fixture, NoAlphaString) {
 CHECK_THROW(p->encrypt(L"1234+8765=9999"),cipher_error);
 }
 
 TEST(MaxShiftKey){
 wstring t15 = L"АДКЪИРМДВОТЧЗРСЪИББНЖГТФДЙПТЁЗСРЮ";
 wstring t16=modAlphaCipher(L"Я").encrypt(L"БЕЛЫЙСНЕГПУШИСТЫЙВВОЗДУХЕКРУЖИТСЯ");
 if (t15==t16) {
 CHECK(true);
 }
 else {
 CHECK(false);
 } 
 }
}
 

SUITE(DecryptText)
{
 TEST_FIXTURE(KeyB_fixture, UpCaseString) {
 wstring t17 = L"БЕЛЫЙСНЕГПУШИСТЫЙВВОЗДУХЕКРУЖИТСЯ";
 wstring t18 = p->decrypt(L"ВЁМЬКТОЁДРФЩЙТУЬКГГПИЕФЦЁЛСФЗЙУТА");
 if (t17==t18) {
 CHECK(true);
 }
 else {
 CHECK(false);
 }
 } 
 
 TEST_FIXTURE(KeyB_fixture, LowCaseString) {
 CHECK_THROW(p->decrypt(L"ЫРМИмиыфтушвыатам"),cipher_error);
 }
 
 TEST_FIXTURE(KeyB_fixture, WhitespaceString) {
 CHECK_THROW(p->decrypt(L"ЫИР МИМ ИЫФ ТУШ ВЫА ТАМ"),cipher_error);
 }
 
 TEST_FIXTURE(KeyB_fixture, DigitsString) {
 CHECK_THROW(p->decrypt(L"ЫРМИмиыфт24146ушвыатам"),cipher_error);
 }
 
 TEST_FIXTURE(KeyB_fixture, PunctString) {
 CHECK_THROW(p->decrypt(L"ЫРМИмиы,фтушвыатам"),cipher_error);
 }
 
 TEST_FIXTURE(KeyB_fixture, EmptyString) {
 CHECK_THROW(p->decrypt(L""),cipher_error);
 }
 
 TEST(MaxShiftKey) {
 wstring t19 = L"БЕЛЫЙСНЕГПУШИСТЫЙВВОЗДУХЕКРУЖИТСЯ";
 wstring t20 = modAlphaCipher(L"Я").decrypt(L"АДКЪИРМДВОТЧЗРСЪИББНЖГТФДЙПТЁЗСРЮ");
 if (t19==t20) {
 CHECK(true);
 }
 else {
 CHECK(false);
 }
 }

}
int main(int argc, char** argv) {
	std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
	return UnitTest::RunAllTests(); }
