# Haming_code_based-ECC-RAM-checksum-simulation
模拟汉明码进行ECC内存校验的小程序，此为初版，尚未采用异或，屎山代码
规则：输入最高11位二进制数字，如果有空位则在结尾填零。
该程序会为11位二进制数字生成5位汉明码，共计16位。
然后根据用户要求，模拟电磁信号造成的比特翻转，最多不超过2位，因为在16位数据中同时出现3位比特翻转的概率可以忽略不计
再对被比特翻转后的数据进行ECC校验，如果只有一位错误数据，则可以定位并修正该错误
