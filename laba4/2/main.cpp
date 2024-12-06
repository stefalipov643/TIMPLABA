#include "TableCipher.h"
#include "tableCipher.cpp"
#include <UnitTest++/UnitTest++.h>
#include <locale>

using namespace std;

SUITE(KeyTest)
{
    TEST(ValidKey) {
        wstring t1 = L"ВИИМРТПЕР";
        wstring t2 = TableCipher(4).encrypt(L"ПРИВЕТМИР");
        if (t1==t2){
        CHECK(true);
    	}
    	else{
    	CHECK(false);
    	}
    	}

    TEST(InvalidKey) {
        CHECK_THROW(TableCipher cp(-4), cipher_error);
    }
    
    TEST(EmptyKey) {
        CHECK_THROW(TableCipher cp(0), cipher_error);
    }
    TEST(BigKey) {
        wstring t1 = L"РИМТЕВИРП";
        wstring t2 = TableCipher(234).encrypt(L"ПРИВЕТМИР");
        if (t1==t2){
        CHECK(true);
    	}
    	else{
    	CHECK(false);
    	}
    	}
    
}

SUITE(EncryptTest)
{
    TEST(ValidText) {
        wstring t1 = L"КНЖТППЧЛАПИИИОКТКНТТСШУЧСЮПИЫДИЕО";
        wstring t2 = TableCipher(5).encrypt(L"ПТИЧКИСОЛНЫШКАЖДУТПТИЧКИПЕСНИПОЮТ");
        if (t1==t2){
        CHECK(true);
    	}
    	else{
    	CHECK(false);
    	}
    }

    TEST(EmptyText) {
        CHECK_THROW(TableCipher(5).encrypt(L""), cipher_error);
    }

    TEST(NonAlphaText) {
        CHECK_THROW(TableCipher(5).encrypt(L"ПРИВЕТ123"), cipher_error);
    }

    TEST(MixedCaseText) {
        wstring t1 = L"КНЖТППЧЛАПИИИОКТКНТТСШУЧСЮПИЫДИЕО";
        wstring t2 = TableCipher(5).encrypt(L"птичкисолнышкаждутптичкипеснипоют");
        if (t1==t2){
        CHECK(true);
    	}
    	else{
    	CHECK(false);
    	}
    }

    TEST(TextWithSpacesAndPunct) {
        wstring t1 = L"КНЖТППЧЛАПИИИОКТКНТТСШУЧСЮПИЫДИЕО";
        wstring t2 = TableCipher(5).encrypt(L"ПТИЧКИ СОЛНЫШКА ЖДУТ, ПТИЧКИ ПЕСНИ ПОЮТ");
        if (t1==t2){
        CHECK(true);
    	}
    	else{
    	CHECK(false);
    	}
    }
}

SUITE(DecryptTest)
{
    TEST(ValidText) {
        wstring t1 = L"ПТИЧКИСОЛНЫШКАЖДУТПТИЧКИПЕСНИПОЮТ";
        wstring t2 = TableCipher(5).decrypt(L"КНЖТППЧЛАПИИИОКТКНТТСШУЧСЮПИЫДИЕО");
        if (t1==t2){
        CHECK(true);
    	}
    	else{
    	CHECK(false);
    	}
    }

    TEST(EmptyText) {
        CHECK_THROW(TableCipher(5).decrypt(L""), cipher_error);
    }

    TEST(NonAlphaText) {
        CHECK_THROW(TableCipher(5).decrypt(L"ПРИВЕТ123"), cipher_error);
    }

    TEST(MixedCaseText) {
        wstring t1 = L"ПРИВЕТМИР";
        wstring t2 = TableCipher(5).decrypt(L"ЕВРИИРМпт");
        if (t1==t2){
        CHECK(true);
    	}
    	else{
    	CHECK(false);
    	}	
    }

    TEST(TextWithSpacesAndPunct) {
        wstring t1 = L"ПРИВЕТМИР";
        wstring t2 = TableCipher(5).decrypt(L"ЕВРИИР МП!Т");
        if (t1==t2){
        CHECK(true);
    	}
    	else{
    	CHECK(false);
    	}	
}
}

int main(int argc, char** argv) {
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
    return UnitTest::RunAllTests();
}
