#include <stdio.h>
#include <ctype.h>
#include <string.h>

main()
{
    int x; //�����±���������鿴����
    int char_count[26]; //26����ĸ����������ͳ��
    for( x= 0; x < 26; x++)
        char_count[x] = 0;
    char str[1024];
    while(gets(str)) {
        for(x = 0; str[x]!=0; ++x)
            if(isalpha(str[x])) //����ĸ��ͳ��
        ++char_count[(str[x]-'a')%32];
        //�ҳ�����Ƶ����ߵ���ĸ
        int max=0;    //����Ƶ����ߵ���ĸ���
        for(x = 0; x < 26; x++)
            if(char_count[x] > char_count[max])
                max = x;
        printf("������Ƶ������ĸ�� %c ,��������%d��\n\n", max+'a',char_count[max]);
		memset(str,0,sizeof(str));
		memset(char_count,0,sizeof(char_count));
    }
    return 0;


}
