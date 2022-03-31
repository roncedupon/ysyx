#include <isa.h>
#include"string.h"
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
  TK_NOTYPE = 256, TK_EQ=255,TK_PLUS=254,TK_SUB=253,TK_MUL=252,TK_DIV=251,TK_BRK_L=250,
  TK_BRK_R=249,
  TK_NUM=248,
  TK_HEX=247,
  TK_STR_NAME=246,
  TK_
  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.--注意不同规则的优先级
   */
  {"\\$[0-9a-zA-Z]+",TK_STR_NAME},
  {"0[xX][0-9a-fA-F]+",TK_HEX},//16进制先被识别
  {"[0-9]+",TK_NUM}, 
  {" +", TK_NOTYPE},    // spaces--匹配全部空格
  {"\\+", TK_PLUS},         // plus--匹配加号,我记得原来这里是\\+,但是\\+匹配的不是+号
  {"==", TK_EQ},        // equal
  {"-",TK_SUB},
  {"\\*",TK_MUL},
  {"/",TK_DIV},
  {"\\(",TK_BRK_L},
  {"\\)",TK_BRK_R},
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
  for (i = 0; i < NR_REGEX; i ++) {//NR_REGE规则数量
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);//ret=0时为成功
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
int tokens_num=0;
static Token tokens[32] __attribute__((used)) = {};//TODO
static int nr_token __attribute__((used))  = 0;
int token_saved[32];
static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;//这玩意是使用正则表达式的

  nr_token = 0;
  int counter_tokens=0;
  while (e[position] != '\0') {//'\0'字符串结束标志位-----⭐每个字符都会被匹配一次
    /* Try all rules one by one. */
  
    for (i = 0; i < NR_REGEX; i ++) {//有多少个规则就for循环多少次
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {//如果匹配到了当前rule的表达式
        char *substr_start = e + position;//e+position表示当前循环匹配字符串的起始位置
        int substr_len = pmatch.rm_eo;
        
        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);
        //int position_tmp=position;
        position += substr_len;
        
        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
          case 256:
            tokens[counter_tokens].type=rules[i].token_type;
            tokens[counter_tokens].str[0]='N';
            printf("啥也不是\n");
            break;
          case 255:
            tokens[counter_tokens].type=rules[i].token_type;
            tokens[counter_tokens].str[0]=' ';
            printf("这是一个空格\n");
            break;
          case 254:
            tokens[counter_tokens].type=rules[i].token_type;
            tokens[counter_tokens].str[0]='+';
            printf("这是一个+号\n");
            break;
          case 253:
            tokens[counter_tokens].type=rules[i].token_type;
            tokens[counter_tokens].str[0]='-';
            printf("这是一个-号\n");
            break;
          case 252:
            tokens[counter_tokens].type=rules[i].token_type;
            tokens[counter_tokens].str[0]='*';
            printf("这是一个*号");
            break;
          case 251:
            tokens[counter_tokens].type=rules[i].token_type;
            tokens[counter_tokens].str[0]='/';
            printf("这是一个/号");
            break;
          case 250:
            tokens[counter_tokens].type=rules[i].token_type;
            tokens[counter_tokens].str[0]='(';
            printf("这是一个(号");
            break;
          case 249:
            tokens[counter_tokens].type=rules[i].token_type;
            tokens[counter_tokens].str[0]=')';
            printf("这是一个)号");
            break;
          case 248:
            tokens[counter_tokens].type=rules[i].token_type;
            memcpy(tokens[counter_tokens].str,e+position-substr_len,sizeof(char)*substr_len);
            //token_saved[counter_tokens]=atoi(tmp);//数字处理比较重要⭐
            printf("这是一个数字%d\n",atoi(tokens[i].str));
            break;
          case TK_HEX:
            printf("这tm是16进制\n");
            break;
          case TK_STR_NAME:
            tokens[counter_tokens].type=rules[i].token_type;
            memcpy(tokens[counter_tokens].str,e+position-substr_len,sizeof(char)*substr_len);
            printf("这tm是一个$字符串\n");
            break;
          default: TODO();
        }
        //把识别出来的token]存起来
        counter_tokens++;
        break;
      }
    }
    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }
  tokens_num=counter_tokens;
  return true;
}
bool check_parentheses(int p,int q){
  if(tokens[p].str[0]=='('&&tokens[q].str[0]==')'){
    printf("找到fuck括号了");
    printf("%c%c\n",tokens[p].str[0],tokens[q].str[0]);
    return true;
  }
  
  return false;//匹配括号
}

word_t eval(int p, int q) {//现在先方便起见,认为所有结果都是uint32_t类型
//输入p为表达式左边界,q为表达式右边界
  if (p > q) {
    return 1;//error
  }
  else if (p == q) {
    if(tokens[p].str[0]=='$'){
        bool success=true;
        return isa_reg_str2val(tokens[p].str,&success);
      }//如果当前token是$字符串,就返回$字符串指示的内存的数据
    return atoi(tokens[p].str);//如果当前左边界等于有边界,那它就是一个number
  }
  else if (check_parentheses(p, q) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
    */
    return eval(p + 1, q - 1);
  }
  else {
  //寻找主运算符
  int32_t  op = p;//the position of 主运算符 in the token expression;
  for(int i=p;i<=q;i++){
    //int main_op=251;
    if(tokens[i].str[0]=='(')
      while(tokens[i].str[0]!=')')i++;//忽略括号内的

    //同级运算符处理
    //+,-*/
  //(20*31/22+(31-32*3))
  if(tokens[i].type==248){
    if(i!=q)
    op++;
    continue;//数字不考虑
  }
    
  if(tokens[op].str[0]=='+'||tokens[op].str[0]=='-'){//如果找到一个同级别或者更低级的运算符
      if(tokens[i].str[0]=='+'||tokens[i].str[0]=='-')
        op=i;
    }
    else{
      //if(tokens[i].str=='+'||tokens[i].str=='-')
        op=i;
    }
  }
  



  
  int32_t  val1 = eval(p, op - 1);
  int32_t  val2 = eval(op + 1, q);
  // TK_NOTYPE = 256, TK_EQ=255,TK_PLUS=254,TK_SUB=253,TK_MUL=252,TK_DIV=251,TK_BRK_L=250,
  // TK_BRK_R=249,
  // TK_NUM=248,
    switch (tokens[op].type) {
      case 254: return val1 + val2;
      case 253: return val1 - val2;
      case 252: return val1 * val2;
      case 251: return val1 / val2;
      default: assert(0);
    }
  }
}

word_t expr(char *e, bool *success) {
  
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  printf("\n识别出了全部token,下面开始表达式求值\n");
  printf("token的个数为%d\n",tokens_num);
  printf("表达式的值为%ld\n",eval(0,tokens_num-1));
  //eval(0,length(tokens));
  /* TODO: Insert codes to evaluate the expression. */
  //TODO();


  return 0;
}
