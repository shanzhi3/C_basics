char* longestCommonPrefix(char** strs, int strsSize) {
    //���������
	if(strsSize == 0){
		char* result = (char*)malloc(1);
		result[0] = '\0';
		return result;
	} 
	
	//��ǰ��鵽������
	int curp = 0;
	while(1){
		char cur = strs[0][curp];
		
		//����һ���ַ�������β 
		if(cur == '\0'){
			break;
		} 
		
		//��һ������
		int k = 1;
		 
		int i;
		for(i = 1; i < strsSize; i++){
			if(strs[i][curp] == '\0'){
				k = 0;  //���ַ����Ѿ������������������رտ��� 
				break;
			} 
            if(strs[i][curp] != strs[0][curp]){
                k = 0;  //���ַ���������������ͬһ������Ԫ�ز�һ���������������رտ��� 
				break;
            }
		}
		
		//���عر�ֹͣ��� 
		if(k == 0){
			break;
		}
		//����Ԫ�غ��� 
		curp++;
	} 
	
	//�ڴ����
	char* result = (char*)malloc(curp + 1);
	//strncpy���ƹ���ǰ׺
	strncpy(result, strs[0], curp);
	// ����ַ���������
    result[curp] = '\0';
    
	return result; 
}
