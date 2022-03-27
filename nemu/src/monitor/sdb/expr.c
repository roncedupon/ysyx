#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>


// bool eval(int p, int q) {
//   if (p > q) {
//     /* Bad expression */
//     return false;
//   }
//   else if (p == q) {
//     /* Single token.
//      * For now this token should be a number.
//      * Return the value of the number.
//      */
//   }
//   else if (check_parentheses(p, q) == true) {
//     /* The expression is surrounded by a matched pair of parentheses.
//      * If that is the case, just throw away the parentheses.
//       其中check_parentheses()函数用于判断表达式是否被一对匹配的括号包围着, 
//       同时检查表达式的左右括号是否匹配, 如果不匹配, 
//       这个表达式肯定是不符合语法的, 也就不需要继续进行求值了
//      */
//     return eval(p + 1, q - 1);
//   }
//   else {
//     /* We should do more things here. */
//   }
// }





enum {
  TK_NOTYPE = 256, TK_EQ=255,TK_PLUS=254

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.--注意不同规则的优先级
   */

  {" +", TK_NOTYPE},    // spaces--匹配全部括号
  {"\\+", TK_PLUS},         // plus--匹配加号,我记得原来这里是\\+,但是\\+匹配的不是+号
  {"==", TK_EQ},        // equal

};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};//初始化
//regex_t 是一个结构体数据类型，用来存放编译后的正则表达式
//它的成员re_nsub 用来存储正则表达式中的子正则表达式的个数，子正则表达式就是用圆括号包起来的部分表达式。
//pattern 是指向我们写好的正则表达式的指针。
/* Rules are used for many times.
 * Therefore we compil---e them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;
/*
这些规则会在简易调试器初始化的时候通过init_regex()被编译成一些用于进行pattern匹配的内部信息, 
这些内部信息是被库函数使用的, 而且它们会被反复使用, 
但你不必关心它们如何组织. 但如果正则表达式的编译不通过, NEMU将会触发assertion fail, 
此时你需要检查编写的规则是否符合正则表达式的语法
*/
  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    //参数1:用来存放编译后的正则表达式
    //参数2:是指向我们写好的正则表达式的指针
    //参数3:REG_EXTENDED 以功能更加强大的扩展正则表达式的方式进行匹配。
      /*
编译正则表达式 regcomp()
匹配正则表达式 regexec()
释放正则表达式 regfree()
  */
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;//类型
  char str[32];//这玩意
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;//这玩意是使用正则表达式的


  nr_token = 0;

  while (e[position] != '\0') {//'\0'字符串结束标志位
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {//有多少个规则就for循环多少次
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
          default: TODO();
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}


word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  TODO();

  return 0;
}
