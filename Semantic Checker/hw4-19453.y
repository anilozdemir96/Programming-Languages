%{
	#include <stdio.h>
	#include <string.h>
	#include "hw4.h"

	void yyerror(const char *s){//called by yyparse on error
		printf("%s\n", s);
	}
	
	 TreeNode * tree_root;

	 extern int noOfLine;

	 int courseLine;
	 int classLine;
	 int meetingLine;
%}


%union {
char * str;
TreeNode * ptr;
}

%token<str> tOPEN tCOURSE tCLOSE tEND tCODE tCLASS  tNAME tTYPE tSTRING tNUM tSECTION  tINSTRUCTOR tCRN  tCAPACITY tMEETING tSELF tDAY tSTART tTIME  tEND_A tMON  tTUE  tWED  tTHU  tFRI tCONSTRAINT tITEM 

%type<ptr> prog elementList element beginCourse endCourse courseAttrList courseAttr classList class beginClass endClass closeClass classAttrList classAttr meetingList meeting beginMeeting endMeeting meetingAttrList meetingAttr day beginConstraint endConstraint itemList item beginItem endItem itemAttr
%%
prog :  elementList {

tree_root = $$;  
 $$ = mkprogNode($1); }
| ;
elementList :  element { $$ = mkelementlistNode_c($1); }
			| element elementList { $$ = mkelementlistNode_cc($1,$2);};
			
element : beginCourse classList endCourse {$$=mkelementNode($1,$2,$3); }
		| beginConstraint itemList endConstraint {$$ = mkelementNode($1,$2,$3);};
		
beginCourse : tOPEN tCOURSE  courseAttrList tCLOSE {courseLine=noOfLine; $$ =mkbegincourseNode( $1,$2,$3,$4); };

endCourse : tEND tCOURSE tCLOSE { $$ = mkendcourseNode($1,$2,$3); };

courseAttrList :  courseAttr { $$ = mkcourseattrlistNode_1($1); }
		|  courseAttr  courseAttrList {$$ = mkcourseattrlistNode_2($1,$2); };

courseAttr : tCODE tSTRING {$$=mkcourseAttrNode($1,$2,"","");}
			| tNAME tSTRING {$$=mkcourseAttrNode($1,"",$2,"");}
			| tTYPE tSTRING {$$=mkcourseAttrNode($1,"","",$2);} 

classList : class {$$ = mkclassListNode1($1);}
			| class classList {$$ = mkclassListNode2($1,$2);};
			
			
class :  beginClass classAttrList endClass meetingList closeClass {$$ = mkclassNode($1,$2,$3,$4,$5);};

beginClass  : tOPEN tCLASS {classLine=noOfLine; $$ =mkbeginclassNode($1,$2); };

endClass :  tCLOSE { $$ = mkendclassNode($1); } ;

closeClass : tEND tCLASS tCLOSE {$$=mkcloseclassNode($1,$2,$3);};

classAttrList :  classAttr { $$ = mkclassattrlistNode1($1); }
			| classAttr classAttrList { $$ = mkclassattrlistNode2($1,$2); };

classAttr : tSECTION tSTRING {$$=mkclassattrNode($1,$2,"","","");}
			| tINSTRUCTOR tSTRING {$$=mkclassattrNode($1,"",$2,"","");}
			|tCRN tNUM {$$=mkclassattrNode($1,"","",$2,"");}
			| tCAPACITY tNUM {$$=mkclassattrNode($1,"","","",$2);};

meetingList : meeting {$$ = mkmeetinglistNode1($1);}
			|meeting  meetingList{ $$ = mkmeetinglistNode2 ($1,$2 ); };

meeting : beginMeeting meetingAttrList endMeeting { $$ = mkmeetingNode($1,$2,$3);};

beginMeeting :  tOPEN tMEETING  {meetingLine=noOfLine; $$ = mkbeginmeetingNode($1,$2 ); } ;

endMeeting :tSELF { $$ = mkendmeetingNode($1); } ;

meetingAttrList : meetingAttr { $$ =mkmeetingattrlistNode1($1); } 
				| meetingAttr meetingAttrList { $$ = mkmeetingattrlistNode2($1,$2); } ;


meetingAttr : tDAY day {$$=mkmeetingattrNode($1,$2,"","");}
			| tSTART tTIME {$$=mkmeetingattrNode($1,NULL,$2,"");}
			| tEND_A tTIME {$$=mkmeetingattrNode($1,NULL,"",$2);};


day : tMON {$$=mkdayNode($1);}
	| tTUE {$$=mkdayNode($1);}
	| tWED {$$=mkdayNode($1);}
	| tTHU {$$=mkdayNode($1);}
	| tFRI {$$=mkdayNode($1);};
	
beginConstraint : tOPEN tCONSTRAINT tCLOSE {$$=mkbeginconstraintNode($1,$2,$3);};


endConstraint : tEND tCONSTRAINT  tCLOSE {$$=mkendconstraintNode($1,$2,$3);};

itemList :  item {$$=mkitemlistNode1($1);}
		| item itemList {$$=mkitemlistNode2($1,$2);};

item :  beginItem itemAttr endItem {$$=mkitemNode($1,$2,$3);};


beginItem : tOPEN tITEM {$$=mkbeginitemNode($1,$2);};

endItem : tSELF {$$=mkenditemNode($1);};

itemAttr: tCODE tSTRING  {$$=mkitemattrNode($1,$2,"");}
		| tCRN tNUM {$$=mkitemattrNode($1,"",$2);};

%%
int main(){
	if(yyparse()){
		printf("ERROR\n");
		return 1;		
	}else{
		printTree(tree_root);
		printf("OK\n");
		return 0;
	}
		
} 
