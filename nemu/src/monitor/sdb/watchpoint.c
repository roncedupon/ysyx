#include "sdb.h"
//监视点
//w EXPR--设置对表达式EXPR的监视--例如:w *0x2000

#define NR_WP 32

typedef struct watchpoint {
  int NO;//监视点的序号
  char *EXPR;//监视点的表达式
  uint32_t EXPR_VALUE;//监视点的值
  struct watchpoint *next;//下一个监视点
  /* TODO: Add more members if necessary */
} WP;
static WP wp_pool[NR_WP] = {};//监视点池
static WP *head = NULL, *free_ = NULL;
//两个链表
//free_用于组织空闲的监视点结构
//head用于组织使用中的监视点结构
//init_wp_pool()函数会对两个链表进行初始化↓
void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);//防止溢出
  }
  head = NULL;
  //head->next=NULL;
  free_ = wp_pool;
}


void new_wp(char*args)//当用户要监视一个表达式时,用new_wp申请一个空的监视点结构
{//其中new_wp()从free_链表中返回一个空闲的监视点结构
 //先从wp_pool中拿一个节点出来用头插法给head链表
 WP*tmp=free_;//先让tmp指向free_
 if(free_->next)
    free_=free_->next;//free_指向free_下一个
 else {
  printf("监视点池没了,被榨干了\n");
  assert(0);
 }
bool success=true;//没有头节点的链表,采用头插法
tmp->EXPR_VALUE=expr(args,&success);
tmp->EXPR=args;
tmp->next=head;
head=tmp;
}
void free_wp(WP *wp){
  //free_wp()将wp归还到free_链表中, 这两个函数会作为监视点池的接口被其它函数调用.
  
}


/* TODO: Implement the functionality of watchpoint */

