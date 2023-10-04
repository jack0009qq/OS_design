#include "os.h"

//len = kstrcspn(bptr,SPACE);//取字結數
//*是字串的首個地址
//SPACE的第一個地址就是' '
size_t kstrcspn(const char *str, const char *charset) {
    size_t len = 0;

    while (str[len] != '\0') {
        int found = 0;
        //charset[i]為了要找到相對應的char
        for (size_t i = 0; charset[i] != '\0'; i++) {
            if (str[len] == charset[i]) {
                found = 1;
                break;
            }
        }

        if (found) {
            break;
        }

        len++;
    }

    return len;
}

int katoi(const char *str) {
    int result = 0;
    int sign = 1; // 1 for positive, -1 for negative
    int i = 0;

    // Handle negative numbers
    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    // Iterate through digits and accumulate the result
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return sign * result;
}
//tmp, bptr, len
void kstrncpy(char *dest, const char *src, size_t n) {
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }

    // 充足够数量的 null 字节，以保证数组长度为 n，即使不是所有位置都被赋值。
    for (; i < n; i++) {
        dest[i] = '\0';
    }
}


int isspace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v';
}

// 自定义函数判断字符是否为数字
int is_digit(char c) {
    return c >= '0' && c <= '9';
}
//跳过输入字符串的前导空白字符，直到遇到第一个非空白字符或换行符，并返回相应的指针位置。
char *check(const char  *line)
{
	while (*line != '\n') {
		if (!isspace(*line))
			return line;
		++line;	
	}
	return line;
}




/*000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000*/


static char line[1000];
// 它是一个静态数组，意味着其生命周期在整个程序运行期间保持不变
// 而不是在特定函数的作用域内。
int scanf(const char *fmt, ...)
{
    char *str, *bptr;
    int len = 0, count = 0, space = 0,*var;
    char SPACE[] = {' '};
	uart_gets(line); //我輸入的值放入line
    va_list ap;                                 
	va_start(ap, fmt);
    bptr = line; //bptr指向line的第一個位元
    char tmp[100];
    while (*fmt) {
		len = 0;
        //去掉空白格 判斷是否空白，是的話往下跳一格
		while (*fmt && isspace(*fmt)) {
			++fmt;
			++space;
		}
        if (!*fmt)
			break;
        if (*fmt == 'd'){
            for (int i = 0; i < 100; i++) {
                tmp[i] = 0;
            }
            bptr = check(bptr);//把空白鍵吃掉
            var = va_arg(ap, int *);//var放變數地址
            len = kstrcspn(bptr,SPACE);//取字結數
            kstrncpy(tmp, bptr, len);//照len數把bptr放入tmp
            *var = (katoi(tmp)>-2147483648)&&(katoi(tmp)<2147483647)?katoi(tmp):0; //防止10位以內造成的overflow
            if (len>10)
                *var = 0;//防止10位以外造成的overflow
            bptr += len;
			++count;    
			space = 0; //???
            }
        else if (*fmt == 's'){
            bptr = check(bptr);//把空白鍵吃掉
            str = va_arg(ap, char *);//var放變數地址
            len = kstrcspn(bptr,SPACE);//取字結數
            kstrncpy(str, bptr, len);
            bptr += len;    //指向bptr的第len個數
			++count;    //
			space = 0; //
            }
        else
            ;
        ++fmt;
    }
	va_end(ap);
    return  count;
}


/*000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000*/

/*000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000*/


/*000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000*/

