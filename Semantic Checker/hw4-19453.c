#include "hw4.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "hw4.tab.h"

extern int courseLine;
extern int classLine;
extern int meetingLine;

char* copy(char* string){
	char* cloned;
	cloned = (char*)malloc(sizeof(char)*strlen(string));
return strcpy(cloned, string);}


void printTree ( TreeNode * tree_root) {
//printf("%d",tree_root != NULL);

if ( tree_root !=NULL) {

	if( tree_root->thisNodeType==PROG)
	{
		printTree( tree_root->exprNodePtr->prog.firstChild);

	}

	else if( tree_root->thisNodeType==ELEMENTLIST1)
	{
		
		printTree(tree_root->exprNodePtr->elementlist1.firstChild);
		
	}

	else if( tree_root->thisNodeType==ELEMENTLIST2)
	{
		
		if(tree_root->exprNodePtr->elementlist2.firstChild->exprNodePtr->elm.thirdChild->thisNodeType == ENDCONSTRAINTNODE)
		{	
			printTree( tree_root->exprNodePtr->elementlist2.secondChild);

			printTree( tree_root->exprNodePtr->elementlist2.firstChild);

			}
		else {
			printTree( tree_root->exprNodePtr->elementlist2.firstChild);

			printTree( tree_root->exprNodePtr->elementlist2.secondChild);



		}

		
	}

	else if( tree_root->thisNodeType==ELM)
	{
		
		printTree( tree_root->exprNodePtr->elm.firstChild);
		printTree( tree_root->exprNodePtr->elm.secondChild);
		printTree( tree_root->exprNodePtr->elm.thirdChild);

	}

	else if( tree_root->thisNodeType==BEGINCOURSE)
	{



		
		//if(tree_root->exprNodePtr->begincourse.thirdChild->exprNodePtr->courseattrlist_1.name==1)
		
		//printf("%s",tree_root->exprNodePtr->begincourse.thirdChild->exprNodePtr->courseattrlist_1.code);
		//printf("%s",tree_root->exprNodePtr->begincourse.thirdChild->exprNodePtr->courseattrlist_1.name);	
		//printf("%s",tree_root->exprNodePtr->begincourse.thirdChild->exprNodePtr->courseattrlist_1.type);

		printf("%s", tree_root->exprNodePtr->begincourse.t1);
		printf("%s", tree_root->exprNodePtr->begincourse.t2);
		printTree( tree_root->exprNodePtr->begincourse.thirdChild);
		printf("%s\n", tree_root->exprNodePtr->begincourse.t4);

	}
	else if( tree_root->thisNodeType==ENDCOURSE)
	{
		
		printf("%s", tree_root->exprNodePtr->endcourse.t1);
		printf("%s",  tree_root->exprNodePtr->endcourse.t2);
		printf( "%s\n", tree_root->exprNodePtr->endcourse.t3);

	}

	else if( tree_root->thisNodeType==COURSEATTRLIST_1)
	{
		
		printTree( tree_root->exprNodePtr->courseattrlist_1.firstChild);

	}
	else if( tree_root->thisNodeType==COURSEATTRLIST_2)
	{
		
		printTree( tree_root->exprNodePtr->courseattrlist_2.firstChild);
		printTree( tree_root->exprNodePtr->courseattrlist_2.secondChild);

	}

	else if( tree_root->thisNodeType==COURSEATTR)
	{
		printf(" %s", tree_root->exprNodePtr->courseattr.token);
		printf("%s", tree_root->exprNodePtr->courseattr.code);
		printf("%s",tree_root->exprNodePtr->courseattr.name);
		printf("%s",tree_root->exprNodePtr->courseattr.type);

	}


	else if( tree_root->thisNodeType==CLASSLIST1)
	{
		
		printTree( tree_root->exprNodePtr->classlist1.firstChild);

	}

	else if( tree_root->thisNodeType==CLASSLIST2)
	{
		
		printTree( tree_root->exprNodePtr->classlist2.firstChild);
		printTree( tree_root->exprNodePtr->classlist2.secondChild);

	}

	else if( tree_root->thisNodeType==CLASSNODE)
	{
		
		printTree( tree_root->exprNodePtr->classnode.firstChild);
		printTree( tree_root->exprNodePtr->classnode.secondChild);
		printTree( tree_root->exprNodePtr->classnode.thirdChild);
		printTree( tree_root->exprNodePtr->classnode.forthChild);
		printTree( tree_root->exprNodePtr->classnode.fiftChild);

	}

	else if( tree_root->thisNodeType==BEGINCLASSNODE)
	{
		
		printf("\t%s",  tree_root->exprNodePtr->beginclassnode.t1);
		printf("%s",  tree_root->exprNodePtr->beginclassnode.t2);

	}
	else if( tree_root->thisNodeType==ENDCLASSNODE)
	{
		
		printf("%s\n",  tree_root->exprNodePtr->endclassnode.t1);

	}

	else if( tree_root->thisNodeType==CLOSECLASSNODE)
	{
		
		printf("\t%s",  tree_root->exprNodePtr->closeclassnode.t1);
		printf("%s",  tree_root->exprNodePtr->closeclassnode.t2);
		printf("%s\n",  tree_root->exprNodePtr->closeclassnode.t3);

	}
	else if( tree_root->thisNodeType==CLASSATTRLISTNODE1)
	{
		
		printTree( tree_root->exprNodePtr->classattrlistnode1.firstChild);

	}


	else if( tree_root->thisNodeType==CLASSATTRLISTNODE2)
	{
		
		printTree( tree_root->exprNodePtr->classattrlistnode2.firstChild);
		printTree( tree_root->exprNodePtr->classattrlistnode2.secondChild);

	}

	else if( tree_root->thisNodeType==CLASSATTRNODE)
	{
		printf(" %s", tree_root->exprNodePtr->classattrnode.token);
		
		printf("%s", tree_root->exprNodePtr->classattrnode.section);
		
		printf("%s", tree_root->exprNodePtr->classattrnode.instructor);
		
		printf("%s", tree_root->exprNodePtr->classattrnode.crn);
		
		printf("%s", tree_root->exprNodePtr->classattrnode.capacity);

	}

	else if( tree_root->thisNodeType==MEETINGLISTNODE1)
	{
		
		printTree( tree_root->exprNodePtr->meetinglistnode1.firstChild);

	}
	else if( tree_root->thisNodeType==MEETINGLISTNODE2)
	{
		
		printTree( tree_root->exprNodePtr->meetinglistnode2.firstChild);
		printTree( tree_root->exprNodePtr->meetinglistnode2.secondChild);

	}

	else if( tree_root->thisNodeType==MEETINGNODE)
	{
		
		printTree( tree_root->exprNodePtr->meetingnode.firstChild);
		printTree( tree_root->exprNodePtr->meetingnode.secondChild);
		printTree( tree_root->exprNodePtr->meetingnode.thirdChild);
		//printTree( tree_root->exprNodePtr->meetingnode.forthChild);

	}
	else if( tree_root->thisNodeType==BEGINMEETINGNODE)
	{
		
		printf("\t\t%s", tree_root->exprNodePtr->beginmeetingnode.t1);
		printf("%s",  tree_root->exprNodePtr->beginmeetingnode.t2);

	}

	else if( tree_root->thisNodeType==ENDMEETINGNODE)
	{
		
		printf("%s\n",  tree_root->exprNodePtr->endmeetingnode.t1);

	}

	else if( tree_root->thisNodeType==MEETINGATTRLISTNODE1)
	{
		
		printTree( tree_root->exprNodePtr->meetingattrlistnode1.firstChild);

	}

	else if( tree_root->thisNodeType==MEETINGATTRLISTNODE2)
	{
		
		printTree( tree_root->exprNodePtr->meetingattrlistnode2.firstChild);
		printTree( tree_root->exprNodePtr->meetingattrlistnode2.secondChild);

	}
/*else if( tree_root->thisNodeType==MEETINGNODE)
{
	
	printTree( tree_root->exprNodePtr->meetingnode.firstChild);
	printTree( tree_root->exprNodePtr->meetingnode.secondChild);
	printTree( tree_root->exprNodePtr->meetingnode.thirdChild);
	printTree( tree_root->exprNodePtr->meetingnode.forthChild);

}*/
/*
else if( tree_root->thisNodeType==BEGINMEETINGNODE)
{
	
	printf( "%s", tree_root->exprNodePtr->beginmeetingnode.t1);
	printf("%s",  tree_root->exprNodePtr->beginmeetingnode.t2);

}*/
/*
else if( tree_root->thisNodeType==ENDMEETINGNODE)
{
	
	printf( tree_root->exprNodePtr->endmeetingnode.t1);

}*/
/*
else if( tree_root->thisNodeType==MEETINGATTRLISTNODE1)
{
	
	printTree( tree_root->exprNodePtr->meetingattrlistnode1.firstChild);

}*/
/*
else if( tree_root->thisNodeType==MEETINGATTRLISTNODE2)
{
	
	printTree( tree_root->exprNodePtr->meetingattrlistnode2.firstChild);
	printTree( tree_root->exprNodePtr->meetingattrlistnode2.secondChild);

}*/

	else if( tree_root->thisNodeType==MEETINGATTRNODE)
	{
		printf(" %s", tree_root->exprNodePtr->meetingattrnode.tday);
		printTree(tree_root->exprNodePtr->meetingattrnode.day);
		printf("%s", tree_root->exprNodePtr->meetingattrnode.time);
		printf("%s", tree_root->exprNodePtr->meetingattrnode.end_time);

	}

	else if( tree_root->thisNodeType==DAYNODE)
	{
		
		printf("%s",  tree_root->exprNodePtr->daynode.day);
		

	}

	else if( tree_root->thisNodeType==BEGINCONSTRAINTNODE)
	{
		
		printf("%s", tree_root->exprNodePtr->beginconstraintnode.t1);
		printf("%s",  tree_root->exprNodePtr->beginconstraintnode.t2);
		printf("%s\n",  tree_root->exprNodePtr->beginconstraintnode.t3);


	}
	else if( tree_root->thisNodeType==ENDCONSTRAINTNODE)
	{
		
		printf("%s",  tree_root->exprNodePtr->endconstraintnode.t1);
		printf("%s",  tree_root->exprNodePtr->endconstraintnode.t2);
		printf("%s\n",  tree_root->exprNodePtr->endconstraintnode.t3);


	}

	else if( tree_root->thisNodeType==ITEMLISTNODE1)
	{
		
		printTree( tree_root->exprNodePtr->itemlistnode1.firstChild);

	}
	else if( tree_root->thisNodeType==ITEMLISTNODE2)
	{
		
		printTree( tree_root->exprNodePtr->itemlistnode2.firstChild);
		printTree( tree_root->exprNodePtr->itemlistnode2.secondChild);

	}

	else if( tree_root->thisNodeType==ITEMNODE)
	{
		
		printTree( tree_root->exprNodePtr->itemnode.firstChild);
		printTree( tree_root->exprNodePtr->itemnode.secondChild);
		printTree( tree_root->exprNodePtr->itemnode.thirdChild);

	}

	else if( tree_root->thisNodeType==BEGINITEMNODE)
	{
		
		printf("\t%s",  tree_root->exprNodePtr->beginitemnode.t1);
		printf("%s",  tree_root->exprNodePtr->beginitemnode.t2);
	}
	else if( tree_root->thisNodeType==ENDITEMNODE)
	{
		
		printf("%s\n",  tree_root->exprNodePtr->enditemnode.t1);
	}
	else if( tree_root->thisNodeType==ITEMATTRNODE)
	{
		printf(" %s", tree_root->exprNodePtr->itemattrnode.token);
		printf("%s", tree_root->exprNodePtr->itemattrnode.code);
		printf("%s", tree_root->exprNodePtr->itemattrnode.crn);
	}	





}

}



TreeNode * mkprogNode ( TreeNode *first) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = PROG;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->prog.firstChild = first;
return (ret);
}

TreeNode * mkelementlistNode_c ( TreeNode *first) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = ELEMENTLIST1;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->elementlist1.firstChild = first;
return (ret);
}

TreeNode * mkelementlistNode_cc ( TreeNode *first,TreeNode *second) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = ELEMENTLIST2;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->elementlist2.firstChild = first;
ret->exprNodePtr->elementlist2.secondChild = second;
return (ret);
}

TreeNode * mkelementNode( TreeNode *first,TreeNode *second,TreeNode* third) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = ELM;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->elm.firstChild = first;
ret->exprNodePtr->elm.secondChild = second;
ret->exprNodePtr->elm.thirdChild = third;
return (ret);
}

TreeNode * mkbegincourseNode( char *t1,char *t2,TreeNode* third ,char * t4) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = BEGINCOURSE;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));

ret->exprNodePtr->begincourse.t1 = t1;
ret->exprNodePtr->begincourse.t2 = t2;
ret->exprNodePtr->begincourse.thirdChild = third;
ret->exprNodePtr->begincourse.t4 = t4;

if(third->exprNodePtr->courseattrlist_1.code >= 1){
		printf("ERROR: course element at line %d has %d occurrences of code\n", courseLine,third->exprNodePtr->courseattrlist_1.code);
	}
if(third->exprNodePtr->courseattrlist_1.name >= 1){
		printf("ERROR: course element at line %d has %d occurrences of name\n", courseLine,third->exprNodePtr->courseattrlist_1.name);
	}
if(third->exprNodePtr->courseattrlist_1.type >=1){
		printf("ERROR: course element at line %d has %d occurrences of type\n", courseLine,third->exprNodePtr->courseattrlist_1.type);
	}
return (ret);
}

TreeNode * mkendcourseNode( char * t1,char *t2,char * t3 ) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = ENDCOURSE;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->endcourse.t1 = t1;
ret->exprNodePtr->endcourse.t2 = t2;
ret->exprNodePtr->endcourse.t3 = t3;
return (ret);
}

TreeNode * mkcourseattrlistNode_1( TreeNode *first) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = COURSEATTRLIST_1;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->courseattrlist_1.firstChild = first;

ret->exprNodePtr->courseattrlist_1.code=0+ret->exprNodePtr->courseattrlist_1.firstChild->exprNodePtr->courseattr.code_num;

ret->exprNodePtr->courseattrlist_1.name=0+ret->exprNodePtr->courseattrlist_1.firstChild->exprNodePtr->courseattr.name_num;

ret->exprNodePtr->courseattrlist_1.type=0+ret->exprNodePtr->courseattrlist_1.firstChild->exprNodePtr->courseattr.type_num;

//ok

return (ret);
}

TreeNode * mkcourseattrlistNode_2 ( TreeNode *first,TreeNode *second) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = COURSEATTRLIST_2;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->courseattrlist_2.firstChild = first;
ret->exprNodePtr->courseattrlist_2.secondChild = second;



ret->exprNodePtr->courseattrlist_2.code=ret->exprNodePtr->courseattrlist_2.firstChild->exprNodePtr->courseattrlist_1.code + ret->exprNodePtr->courseattrlist_2.secondChild->exprNodePtr->courseattrlist_2.code;
ret->exprNodePtr->courseattrlist_2.name=ret->exprNodePtr->courseattrlist_2.firstChild->exprNodePtr->courseattrlist_1.name + ret->exprNodePtr->courseattrlist_2.secondChild->exprNodePtr->courseattrlist_2.name;
ret->exprNodePtr->courseattrlist_2.type=ret->exprNodePtr->courseattrlist_2.firstChild->exprNodePtr->courseattrlist_1.type + ret->exprNodePtr->courseattrlist_2.secondChild->exprNodePtr->courseattrlist_2.type;

//ret->exprNodePtr->courseattrlist_2.name=ret->exprNodePtr->courseattrlist_2.firstChild->exprNodePtr->courseattrlist_1.name + ret->exprNodePtr->courseattrlist_2.name;

//ret->exprNodePtr->courseattrlist_2.type=ret->exprNodePtr->courseattrlist_2.firstChild->exprNodePtr->courseattrlist_1.type + ret->exprNodePtr->courseattrlist_2.type;


//printf("%s",ret->exprNodePtr->courseattrlist_2.code);

//printf("%s",ret->exprNodePtr->courseattrlist_2.name);


return (ret);


}



TreeNode * mkcourseAttrNode ( char* token,char *c ,char*n, char*t) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = COURSEATTR;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->courseattr.token = token;
ret->exprNodePtr->courseattr.code = c;
ret->exprNodePtr->courseattr.name = n;
ret->exprNodePtr->courseattr.type = t;


	if(c!=""){
	ret->exprNodePtr->courseattr.code_num =1;
	ret->exprNodePtr->courseattr.name_num =0;
	ret->exprNodePtr->courseattr.type_num =0;
	

	}

	else if(n!=""){
	ret->exprNodePtr->courseattr.code_num =0;
	ret->exprNodePtr->courseattr.name_num =1;
	ret->exprNodePtr->courseattr.type_num =0;



	}

	else if(t!=""){
	ret->exprNodePtr->courseattr.code_num =0;
	ret->exprNodePtr->courseattr.name_num =0;
	ret->exprNodePtr->courseattr.type_num =1;

	}


	//printf("%s",ret->exprNodePtr->courseattr.code_num );
	//printf("%s",ret->exprNodePtr->courseattr.name_num );
	//printf("%s",ret->exprNodePtr->courseattr.type_num );


	

return (ret);
}

TreeNode * mkclassListNode1( TreeNode *first) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = CLASSLIST1;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->classlist1.firstChild = first;


return (ret);
}

TreeNode * mkclassListNode2 ( TreeNode *first,TreeNode *second) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = CLASSLIST2;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->classlist2.firstChild = first;
ret->exprNodePtr->classlist2.secondChild = second;



return (ret);
}


TreeNode * mkclassNode( TreeNode *first,TreeNode *second,TreeNode* third ,TreeNode*forth , TreeNode*fift) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = CLASSNODE;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->classnode.firstChild = first;
ret->exprNodePtr->classnode.secondChild = second;
ret->exprNodePtr->classnode.thirdChild = third;
ret->exprNodePtr->classnode.forthChild = forth;
ret->exprNodePtr->classnode.fiftChild = fift;



if(second->exprNodePtr->classattrlistnode1.section != 1){
		printf("ERROR: course element at line %d has %d occurrences of 		printf("ERROR: course element at line %d has %d occurrences of code\n", classLine,second->exprNodePtr->classattrlistnode1.section);
\n", classLine,second->exprNodePtr->classattrlistnode1.section);
	}
if(second->exprNodePtr->classattrlistnode1.instructor != 1){
		printf("ERROR: course element at line %d has %d occurrences of instructor\n", classLine,second->exprNodePtr->classattrlistnode1.instructor);
	}
if(second->exprNodePtr->classattrlistnode1.crn !=1){
		printf("ERROR: course element at line %d has %d occurrences of crn\n", classLine,second->exprNodePtr->classattrlistnode1.crn);
	}

if(second->exprNodePtr->classattrlistnode1.capacity !=1){
		printf("ERROR: course element at line %d has %d occurrences of capacity\n", classLine,second->exprNodePtr->classattrlistnode1.capacity);
	}







return (ret);
}

TreeNode * mkbeginclassNode( char *t1,char * t2) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = BEGINCLASSNODE;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->beginclassnode.t1 = t1;
ret->exprNodePtr->beginclassnode.t2 = t2;











return (ret);
}

TreeNode * mkendclassNode( char *t1) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = ENDCLASSNODE;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->endclassnode.t1 = t1;
return (ret);
}

TreeNode * mkcloseclassNode( char * t1,char * t2, char * t3) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = CLOSECLASSNODE;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->closeclassnode.t1 = t1;
ret->exprNodePtr->closeclassnode.t2 = t2;
ret->exprNodePtr->closeclassnode.t3 = t3;

return (ret);
}

TreeNode * mkclassattrlistNode1( TreeNode *first) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = CLASSATTRLISTNODE1;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->classattrlistnode1.firstChild = first;



ret->exprNodePtr->classattrlistnode1.section=0+ret->exprNodePtr->classattrlistnode1.firstChild->exprNodePtr->classattrnode.section_num;

ret->exprNodePtr->classattrlistnode1.instructor=0+ret->exprNodePtr->classattrlistnode1.firstChild->exprNodePtr->classattrnode.instructor_num;

ret->exprNodePtr->classattrlistnode1.crn=0+ret->exprNodePtr->classattrlistnode1.firstChild->exprNodePtr->classattrnode.crn_num;

ret->exprNodePtr->classattrlistnode1.capacity=0+ret->exprNodePtr->classattrlistnode1.firstChild->exprNodePtr->classattrnode.capacity_num;



return (ret);
}

TreeNode * mkclassattrlistNode2( TreeNode *first,TreeNode * second) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = CLASSATTRLISTNODE2;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->classattrlistnode2.firstChild = first;
ret->exprNodePtr->classattrlistnode2.secondChild =second;


ret->exprNodePtr->classattrlistnode2.section=ret->exprNodePtr->classattrlistnode2.firstChild->exprNodePtr->classattrlistnode1.section + ret->exprNodePtr->classattrlistnode2.secondChild->exprNodePtr->classattrlistnode2.section;
ret->exprNodePtr->classattrlistnode2.instructor=ret->exprNodePtr->classattrlistnode2.firstChild->exprNodePtr->classattrlistnode1.instructor + ret->exprNodePtr->classattrlistnode2.secondChild->exprNodePtr->classattrlistnode2.instructor;
ret->exprNodePtr->classattrlistnode2.crn=ret->exprNodePtr->classattrlistnode2.firstChild->exprNodePtr->classattrlistnode1.crn + ret->exprNodePtr->classattrlistnode2.secondChild->exprNodePtr->classattrlistnode2.crn;
ret->exprNodePtr->classattrlistnode2.capacity=ret->exprNodePtr->classattrlistnode2.firstChild->exprNodePtr->classattrlistnode1.capacity + ret->exprNodePtr->classattrlistnode2.secondChild->exprNodePtr->classattrlistnode2.capacity;



return (ret);
}


TreeNode * mkclassattrNode ( char* token, char *sec ,char* inst,char*crn,char*cap) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = CLASSATTRNODE;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->classattrnode.token = token;

ret->exprNodePtr->classattrnode.section = sec;
ret->exprNodePtr->classattrnode.instructor = inst;
ret->exprNodePtr->classattrnode.crn = crn;
ret->exprNodePtr->classattrnode.capacity = cap;

	if(sec!=""){
	ret->exprNodePtr->classattrnode.section_num =1;
	ret->exprNodePtr->classattrnode.instructor_num =0;
	ret->exprNodePtr->classattrnode.crn_num =0;
	ret->exprNodePtr->classattrnode.capacity_num =0;


	}

	else if(inst!=""){
	ret->exprNodePtr->classattrnode.section_num =0;
	ret->exprNodePtr->classattrnode.instructor_num =1;
	ret->exprNodePtr->classattrnode.crn_num =0;
	ret->exprNodePtr->classattrnode.capacity_num =0;



	}

	else if(crn!=""){
	ret->exprNodePtr->classattrnode.section_num =0;
	ret->exprNodePtr->classattrnode.instructor_num =0;
	ret->exprNodePtr->classattrnode.crn_num =1;
	ret->exprNodePtr->classattrnode.capacity_num =0;

	}

	else if(cap!=""){
	ret->exprNodePtr->classattrnode.section_num =0;
	ret->exprNodePtr->classattrnode.instructor_num =0;
	ret->exprNodePtr->classattrnode.crn_num =0;
	ret->exprNodePtr->classattrnode.capacity_num =1;

	}








return (ret);
}

TreeNode * mkmeetinglistNode1( TreeNode *first) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = MEETINGLISTNODE1;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->meetinglistnode1.firstChild = first;
return (ret);
}



TreeNode * mkmeetinglistNode2( TreeNode *first,TreeNode * second) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = MEETINGATTRLISTNODE2;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->meetinglistnode2.firstChild = first;
ret->exprNodePtr->meetinglistnode2.secondChild = second;

return (ret);
}



TreeNode * mkmeetingNode( TreeNode *first,TreeNode *second,TreeNode* third ) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = MEETINGNODE;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->meetingnode.firstChild = first;
ret->exprNodePtr->meetingnode.secondChild = second;
ret->exprNodePtr->meetingnode.thirdChild = third;

return (ret);
}

TreeNode * mkbeginmeetingNode( char * t1,char * t2) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = BEGINMEETINGNODE;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->beginmeetingnode.t1 = t1;
ret->exprNodePtr->beginmeetingnode.t2 = t2;

return (ret);
}

TreeNode * mkendmeetingNode( char *t1) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = ENDMEETINGNODE;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->endmeetingnode.t1 = t1;
return (ret);
}

TreeNode * mkmeetingattrlistNode1( TreeNode *first) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = MEETINGATTRLISTNODE1;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->meetingattrlistnode1.firstChild = first;
return (ret);
}


TreeNode * mkmeetingattrlistNode2( TreeNode *first,TreeNode * second) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = MEETINGATTRLISTNODE2;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->meetingattrlistnode2.firstChild = first;
ret->exprNodePtr->meetingattrlistnode2.secondChild = second;



return (ret);
}


TreeNode * mkmeetingattrNode ( char* tday, TreeNode* day ,char* time,char*end_time) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = MEETINGATTRNODE;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->meetingattrnode.tday = tday;
ret->exprNodePtr->meetingattrnode.day = day;
ret->exprNodePtr->meetingattrnode.time = time;
ret->exprNodePtr->meetingattrnode.end_time = end_time;

return (ret);
}

TreeNode * mkdayNode ( char *day ) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = DAYNODE;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->daynode.day = day;
return (ret);
}


TreeNode * mkbeginconstraintNode( char *t1,char  *t2,char* t3 ) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = BEGINCONSTRAINTNODE;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->beginconstraintnode.t1 = t1;
ret->exprNodePtr->beginconstraintnode.t2 = t2;
ret->exprNodePtr->beginconstraintnode.t3 = t3;
return (ret);
}


TreeNode * mkendconstraintNode( char * t1,char *t2,char * t3 ) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = ENDCONSTRAINTNODE;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->endconstraintnode.t1 = t1;
ret->exprNodePtr->endconstraintnode.t2 = t2;
ret->exprNodePtr->endconstraintnode.t3 = t3;
return (ret);
}

TreeNode * mkitemlistNode1( TreeNode *first) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = ITEMLISTNODE1;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->itemlistnode1.firstChild = first;
return (ret);
}
TreeNode * mkitemlistNode2( TreeNode *first,TreeNode * second) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = ITEMLISTNODE2;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->itemlistnode2.firstChild = first;
ret->exprNodePtr->itemlistnode2.secondChild = second;
return (ret);
}

TreeNode * mkitemNode( TreeNode *first,TreeNode *second,TreeNode* third ) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = ITEMNODE;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->itemnode.firstChild = first;
ret->exprNodePtr->itemnode.secondChild = second;
ret->exprNodePtr->itemnode.thirdChild = third;
return (ret);
}

TreeNode * mkbeginitemNode( char *t1,char * t2) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = BEGINITEMNODE;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->beginitemnode.t1 = t1;
ret->exprNodePtr->beginitemnode.t2 = t2;
return (ret);
}
TreeNode * mkenditemNode( char *t1) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = ENDITEMNODE;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->enditemnode.t1 = t1;
return (ret);
}

TreeNode * mkitemattrNode ( char* token,char *code ,char* crn) {
TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
ret->thisNodeType = ITEMATTRNODE;
ret->exprNodePtr = (ExprNode *)malloc (sizeof(ExprNode));
ret->exprNodePtr->itemattrnode.token = token;
ret->exprNodePtr->itemattrnode.code = code;
ret->exprNodePtr->itemattrnode.crn = crn;

return (ret);
}