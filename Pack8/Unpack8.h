#pragma once
#include "windows.h"
#define SIGNCH(a,m) if((a)&(m)){(a)|=(0xffffffff ^ ((m)-1));}
//-------------------------------------------------------- -
//1 / 0	  : (0) xxxx'0000	                              |											|										  |
//5 / 4   : (8) xxxx'0001	aaaa'bbbb cccc'dddd eeee'ffff | hhhh'gggg								|									      |											|										  |
//6 / 5   : (4) xxxx'0010	aaaa'abbb bbcc'cccd dddd'eeee | efff'ffhh hhhg'gggg						|										  |											|										  |
//7 / 6   : (C) xxxx'0011	aaaa'aabb bbbb'cccc ccdd'dddd | eeee'eeff ffff'hhhh hhgg'gggg			|					     				  |											|										  |
//8 / 7   : (2) xxxx'0100	aaaa'aaab bbbb'bbcc cccc'cddd | dddd'eeee eeef'ffff ffhh'hhhh hggg'gggg |										  |											|										  |
//9 / 8   : (A) xxxx'0101	aaaa'aaaa bbbb'bbbb cccc'cccc | dddd'dddd eeee'eeee ffff'ffff hhhh'hhhh | gggg'gggg								  |											|										  |
//10 / 9  : (6) xxxx'0110	aaaa'aaaa abbb'bbbb bbcc'cccc | cccd'dddd dddd'eeee eeee'efff ffff'ffhh | hhhh'hhhg gggg'gggg					  |											|										  |
//11 / 10 : (E) xxxx'0111	aaaa'aaaa aabb'bbbb bbbb'cccc | cccc'ccdd dddd'dddd eeee'eeee eeff'ffff | ffff'hhhh hhhh'hhgg gggg'gggg			  |											|										  |
//12 / 11 : (1) xxxx'1000	aaaa'aaaa aaab'bbbb bbbb'bbcc | cccc'cccc cddd'dddd dddd'eeee eeee'eeef | ffff'ffff ffhh'hhhh hhhh'hggg gggg'gggg |											|										  |
//13 / 12 : (9) xxxx'1001	aaaa'aaaa aaaa'bbbb bbbb'bbbb | cccc'cccc cccc'dddd dddd'dddd eeee'eeee | eeee'ffff ffff'ffff hhhh'hhhh hhhh'gggg | gggg'gggg								|										  |
//14 / 13 : (5) xxxx'1010	aaaa'aaaa aaaa'abbb bbbb'bbbb | bbcc'cccc cccc'cccd dddd'dddd dddd'eeee | eeee'eeee efff'ffff ffff'ffhh hhhh'hhhh | hhhg'gggg gggg'gggg						|										  |
//15 / 14 : (D) xxxx'1011	aaaa'aaaa aaaa'aabb bbbb'bbbb | bbbb'cccc cccc'cccc ccdd'dddd dddd'dddd | eeee'eeee eeee'eeff ffff'ffff ffff'hhhh | hhhh'hhhh hhgg'gggg gggg'gggg			|										  |
//16 / 15 : (3) xxxx'1100	aaaa'aaaa aaaa'aaab bbbb'bbbb | bbbb'bbcc cccc'cccc cccc'cddd dddd'dddd | dddd'eeee eeee'eeee eeef'ffff ffff'ffff | ffhh'hhhh hhhh'hhhh hggg'gggg gggg'gggg |										  |
//17 / 16 : (B) xxxx'1101   aaaa'aaaa aaaa'aaaa bbbb'bbbb | bbbb'bbbb cccc'cccc cccc'cccc dddd'dddd | dddd'dddd eeee'eeee eeee'eeee ffff'ffff | ffff'ffff hhhh'hhhh hhhh'hhhh gggg'gggg | gggg'gggg					 			  |
//21 / 20 : (7) xxxx'1110	aaaa'aaaa aaaa'aaaa aaaa'bbbb | bbbb'bbbb bbbb'bbbb cccc'cccc cccc'cccc | cccc'dddd dddd'dddd dddd'dddd eeee'eeee | eeee'eeee eeee'ffff ffff'ffff ffff'ffff | hhhh'hhhh hhhh'hhhh hhhh'gggg gggg'gggg | gggg'gggg
////--------------------------------------------------------

typedef void(*typeUnpack8Funcs) (unsigned char * _src, long * _dst);

void UnPack8_NULL(unsigned char * _src, long * _dst){}

const typeUnpack8Funcs Unpack8Funcs[] =
{
	UnPack8_NULL,	//0
	UnPack8_11,		//1
	UnPack8_7,
	UnPack8_15,
	UnPack8_5,
	UnPack8_7,
	UnPack8_7,
	UnPack8_7,
	UnPack8_7,
	UnPack8_7,
	UnPack8_7,
	UnPack8_7
};