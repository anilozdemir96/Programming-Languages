#ifndef __HW4_H
#define __HW4_H





typedef enum { PROG, ELEMENTLIST1 ,ELEMENTLIST2,ELM,BEGINCOURSE,ENDCOURSE,COURSEATTRLIST_1,COURSEATTRLIST_2,COURSEATTR,CLASSLIST1,CLASSLIST2,CLASSNODE,BEGINCLASSNODE,ENDCLASSNODE,CLOSECLASSNODE,CLASSATTRLISTNODE1,CLASSATTRLISTNODE2, CLASSATTRNODE,MEETINGLISTNODE1,MEETINGLISTNODE2,MEETINGNODE,BEGINMEETINGNODE,ENDMEETINGNODE,MEETINGATTRLISTNODE1,MEETINGATTRLISTNODE2,MEETINGATTRNODE, DAYNODE,BEGINCONSTRAINTNODE,ENDCONSTRAINTNODE, ITEMLISTNODE1,ITEMLISTNODE2,ITEMNODE,BEGINITEMNODE,ENDITEMNODE,ITEMATTRNODE} NodeType;

typedef struct progNode {
struct TreeNode * firstChild;
} progNode;

typedef struct elementlistNode_c {
struct TreeNode * firstChild;
} elementlistNode_c;

typedef struct elementlistNode_cc {
struct TreeNode * firstChild;
struct TreeNode * secondChild;
} elementlistNode_cc;

typedef struct elementNode{
struct TreeNode * firstChild;
struct TreeNode * secondChild;
struct TreeNode * thirdChild;
} elementNode;

typedef struct begincourseNode {
char * t1;
char * t2;
struct TreeNode * thirdChild;
char * t4;
} begincourseNode;

typedef struct endcourseNode {
 char * t1;
 char * t2;
 char * t3;
} endcourseNode;

typedef struct courseattrlistNode_1 {
struct TreeNode * firstChild;
int code;
int name;
int type;
} courseattrlistNode_1;

typedef struct courseattrlistNode_2 {
struct TreeNode * firstChild;
struct TreeNode * secondChild;
int code;
int name;
int type;

} courseattrlistNode_2;

typedef struct courseAttrNode {
char * token;
char * code;
char * name;
char * type;

int code_num ;
int type_num ;
int name_num ;

} courseAttrNode;

typedef struct classListNode1 {
struct TreeNode * firstChild;
} classListNode1;

typedef struct classListNode2 {
struct TreeNode * firstChild;
struct TreeNode * secondChild;
} classListNode2;


typedef struct classNode {
struct TreeNode * firstChild;
struct TreeNode * secondChild;
struct TreeNode * thirdChild;
struct TreeNode * forthChild;
struct TreeNode * fiftChild;
} classNode;

typedef struct beginclassNode {
 char * t1;
 char * t2;
} beginclassNode;

typedef struct endclassNode {
char * t1;
} endclassNode;


typedef struct closeclassNode {
char * t1;
char * t2;
char * t3;
} closeclassNode;

typedef struct classattrlistNode1 {
struct TreeNode * firstChild;
int section;
int instructor;
int crn;
int capacity;
} classattrlistNode1;

typedef struct classattrlistNode2 {
struct TreeNode * firstChild;
struct TreeNode * secondChild;
int section;
int instructor;
int crn;
int capacity;
} classattrlistNode2;

typedef struct classattrNode {
char * token;
char* section;
char* instructor;
char* crn;
char* capacity;
int section_num;
int instructor_num;
int crn_num;
int capacity_num;

} classattrNode;

typedef struct meetinglistNode1 {
struct TreeNode * firstChild;
} meetinglistNode1;

typedef struct meetinglistNode2 {
struct TreeNode * firstChild;
struct TreeNode * secondChild;
} meetinglistNode2;
typedef struct meetingNode {
struct TreeNode * firstChild;
struct TreeNode * secondChild;
struct TreeNode * thirdChild;
} meetingNode;
typedef struct beginmeetingNode {
 char * t1;
 char * t2;
} beginmeetingNode;

typedef struct endmeetingNode {
char * t1;
} endmeetingNode;

typedef struct meetingattrlistNode1 {
struct TreeNode * firstChild;
} meetingattrlistNode1;

typedef struct meetingattrlistNode2 {
struct TreeNode * firstChild;
struct TreeNode * secondChild;
} meetingattrlistNode2;

typedef struct meetingattrNode {
har * tday;
sctruct TreeNode * day;
char * time;
char *end_time;
} meetingattrNode;

typedef struct dayNode {
char * day; //?
} dayNode;

typedef struct beginconstraintNode {
char * t1;
char * t2;
char * t3;
} beginconstraintNode;

typedef struct endconstraintNode {
char * t1;
char * t2;
char * t3;
} endconstraintNode;


typedef struct itemlistNode1 {
struct TreeNode * firstChild;
} itemlistNode1;

typedef struct itemlistNode2 {
struct TreeNode * firstChild;
struct TreeNode * secondChild;
} itemlistNode2;

typedef struct itemNode {
struct TreeNode * firstChild;
struct TreeNode * secondChild;
struct TreeNode * thirdChild;
} itemNode;

typedef struct beginitemNode {
char * t1;
char * t2;
} beginitemNode;

typedef struct enditemNode {
char *t1 ;
} enditemNode;


typedef struct itemattrNode {
char * token;
char* code;
char* crn;
} itemattrNode;

typedef union {
progNode prog;
elementlistNode_c elementlist1;
elementlistNode_cc elementlist2; 
elementNode elm;
begincourseNode begincourse;
endcourseNode endcourse;
courseattrlistNode_1  courseattrlist_1;
courseattrlistNode_2  courseattrlist_2;
courseAttrNode courseattr;
classListNode1 classlist1;
classListNode2 classlist2;
classNode classnode;
beginclassNode beginclassnode;
endclassNode endclassnode;
closeclassNode closeclassnode;
classattrlistNode1 classattrlistnode1;
classattrlistNode2 classattrlistnode2;
classattrNode classattrnode;
meetinglistNode1 meetinglistnode1;
meetinglistNode2 meetinglistnode2;
meetingNode meetingnode;
beginmeetingNode beginmeetingnode;
endmeetingNode endmeetingnode;
meetingattrlistNode1 meetingattrlistnode1;
meetingattrlistNode2 meetingattrlistnode2;
meetingattrNode meetingattrnode;
dayNode daynode;
beginconstraintNode beginconstraintnode;
endconstraintNode endconstraintnode;
itemlistNode1 itemlistnode1;
itemlistNode2 itemlistnode2;
itemNode itemnode;
beginitemNode beginitemnode;
enditemNode enditemnode;
itemattrNode itemattrnode;
} ExprNode;

typedef struct TreeNode {
NodeType thisNodeType;
ExprNode * exprNodePtr;
} TreeNode;

char* copy(char* string);
void printTree ( TreeNode * tree_root);
TreeNode * mkprogNode ( TreeNode *first);
TreeNode * mkelementlistNode_c ( TreeNode *first);
TreeNode * mkelementlistNode_cc ( TreeNode *first,TreeNode *second);
TreeNode * mkelementNode( TreeNode *first,TreeNode *second,TreeNode* third);
TreeNode * mkbegincourseNode( char *t1,char *t2,TreeNode* third ,char*t4);
TreeNode * mkendcourseNode( char *t1,char *t2,char* t3 );
TreeNode * mkcourseattrlistNode_1( TreeNode *first);
TreeNode * mkcourseattrlistNode_2 ( TreeNode *first,TreeNode *second);
TreeNode * mkcourseAttrNode ( char* token,char *c ,char*n, char*t);
TreeNode * mkclassListNode1( TreeNode *first);
TreeNode * mkclassListNode2 ( TreeNode *first,TreeNode *second);
TreeNode * mkclassNode( TreeNode *first,TreeNode *second,TreeNode* third ,TreeNode*forth , TreeNode*fift);
TreeNode * mkbeginclassNode( char *t1,char * t2);
TreeNode * mkendclassNode( char *t1);
TreeNode * mkcloseclassNode( char *t1,char * t2, char * t3);
TreeNode * mkclassattrlistNode1( TreeNode *first);
TreeNode * mkclassattrlistNode2( TreeNode *first,TreeNode * second);
TreeNode * mkclassattrNode ( char* token, char *sec ,char* inst,char*crn,char*cap);
TreeNode * mkmeetinglistNode1( TreeNode *first);
TreeNode * mkmeetinglistNode2( TreeNode *first,TreeNode * second);
TreeNode * mkmeetingNode( TreeNode *first,TreeNode *second,TreeNode* third );
TreeNode * mkbeginmeetingNode( char *t1,char * t2);
TreeNode * mkendmeetingNode( char *t1);
TreeNode * mkmeetingattrlistNode1( TreeNode *first);
TreeNode * mkmeetingattrlistNode2( TreeNode *first,TreeNode * second);
TreeNode * mkmeetingattrNode ( char* tday, TreeNode* day ,char* time,char*end_time);
TreeNode * mkdayNode ( char *day );
TreeNode * mkbeginconstraintNode( char *t1,char *t2,char* t3 );
TreeNode * mkendconstraintNode( char *t1,char *t2,char* t3 );
TreeNode * mkitemlistNode1( TreeNode *first);
TreeNode * mkitemlistNode2( TreeNode *first,TreeNode * second);
TreeNode * mkitemNode( TreeNode *first,TreeNode *second,TreeNode* third );
TreeNode * mkbeginitemNode( char * t1 , char * t2);
TreeNode * mkenditemNode( char *t1);
TreeNode * mkitemattrNode ( char* token,char *code ,char* crn);
#endif