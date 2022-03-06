int lengthOfLastWord(char * s){
	int len = strlen(s);
	int index = len - 1;
	int count = 0;
	while (s[index] == ' ') {
		index--;		
	}
	while (index >=0 && s[index] != ' ') {
		count++;
	}
	return count;
}