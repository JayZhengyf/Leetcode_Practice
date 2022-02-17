// 形成一个编码表，解析每一位的数字，得到编码
const char* thousands[] = {"", "M", "MM" , "MMM"};
const char* hundreds[] = {"", "C", "CC", "CCC", 
"CD", "D", "DC", "DCC", "DCCC", "CM"}; 
const char* tens[] = {"", "X", "XX", "XXX", "XL",
"L", "LX", "LXX", "LXXX", "XC"};
const char* ones[] = {"", "I", "II", "III", "IV",
"V", "VI", "VII", "VIII", "IX"};

char* inToRoman(int num) {
	// 本题最大数字为3999，转换为罗马数字需要15位
	// 15位＋'\0'，因此，申请16为位
	char* roman = malloc(sizeof(char) * 16);
	roman[0] = '\0';
	strcpy(roman + strlen(roman), thousands[num / 1000]);
	strcpy(roman + strlen(roman), hundreds[num % 1000 / 100]);
	strcpy(roman + strlen(roman), tens[num % 100 / 10]);
	strcpy(roman + strlen(roman), ones[num % 10]);
	
	return roman;
}	