char* longestCommonPrefix(char** strs, int strsSize) {
    //空输入情况
	if(strsSize == 0){
		char* result = (char*)malloc(1);
		result[0] = '\0';
		return result;
	} 
	
	//当前检查到哪里了
	int curp = 0;
	while(1){
		char cur = strs[0][curp];
		
		//其中一个字符串到结尾 
		if(cur == '\0'){
			break;
		} 
		
		//设一个开关
		int k = 1;
		 
		int i;
		for(i = 1; i < strsSize; i++){
			if(strs[i][curp] == '\0'){
				k = 0;  //有字符串已经结束，不满足条件关闭开关 
				break;
			} 
            if(strs[i][curp] != strs[0][curp]){
                k = 0;  //无字符串结束，但出现同一列数组元素不一样，不满足条件关闭开关 
				break;
            }
		}
		
		//开关关闭停止检查 
		if(k == 0){
			break;
		}
		//数组元素后移 
		curp++;
	} 
	
	//内存分配
	char* result = (char*)malloc(curp + 1);
	//strncpy复制公共前缀
	strncpy(result, strs[0], curp);
	// 添加字符串结束符
    result[curp] = '\0';
    
	return result; 
}
