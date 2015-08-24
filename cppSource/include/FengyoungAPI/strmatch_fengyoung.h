#ifndef __STRING_MATCH__PURE_C_VERSION___H_
#define __STRING_MATCH__PURE_C_VERSION___H_

#define MATCH_DEBUG_FENGYOUNG

#ifdef MATCH_DEBUG_FENGYOUNG
#define MTRACE_FENGYOUNG( fmt, args... ) printf( fmt, ##args )
#else
#define MTRACE_FENGYOUNG( fmt, args... )
#endif


#define KN_FENGYOUNG 	  256  //the input character is 8 bits.
#define STATE_FENGYOUNG  int

#define F_TERMINATE_FENGYOUNG 0x80000000
#define FIND_MATCHCASE_FENGYOUNG 0x01



#ifdef __cplusplus
extern "C" {
#endif


typedef STATE_FENGYOUNG (*STATE_SLIST_FENGYOUNG)[KN_FENGYOUNG+1]; 

typedef struct {
	unsigned char  *word;
	int gram;
	int	length;
	int   	findnum;
	int   	type;
	int	id;
}KEYWORD_FENGYOUNG; 

typedef struct {
	STATE_SLIST_FENGYOUNG states;
	KEYWORD_FENGYOUNG    *wordlist;
	int	   wordlistlength;
	int	   wordsnum;
	STATE_FENGYOUNG      wordslength;
	int	   totalfind;
	STATE_FENGYOUNG      usedstates;	
}MATCHENTRY_FENGYOUNG;

MATCHENTRY_FENGYOUNG * strMatchInit_fengyoung(int nSize);

int refreshMachine_fengyoung(char* file, int idx);
char *findKeyWord_fengyoung(char *data_buf, int idx);

int Addword_fengyoung(const char *word,int len, MATCHENTRY_FENGYOUNG *entry, int gram);
int AddwordWithID_fengyoung(int id, const char *word,int len, MATCHENTRY_FENGYOUNG *entry);
char *FindUntilNull_fengyoung(const char *p, int *word, STATE_FENGYOUNG state, MATCHENTRY_FENGYOUNG *entry);
char *FindUntilLen_fengyoung(int num, const char *p, int *word, STATE_FENGYOUNG state, MATCHENTRY_FENGYOUNG *entry);
STATE_FENGYOUNG FindAllUntilNull_fengyoung(const char *p,STATE_FENGYOUNG state, MATCHENTRY_FENGYOUNG *entry);
STATE_FENGYOUNG FindAllUntilLen_fengyoung(int num, const char *p,STATE_FENGYOUNG state, MATCHENTRY_FENGYOUNG *entry);
int Prepare_fengyoung(int model, MATCHENTRY_FENGYOUNG *entry);
void RemoveEntry_fengyoung(MATCHENTRY_FENGYOUNG *entry);
char * Getword_fengyoung(int word, MATCHENTRY_FENGYOUNG *entry);
int Getwordid_fengyoung(int word, MATCHENTRY_FENGYOUNG *entry);
int Getwordsnum_fengyoung(MATCHENTRY_FENGYOUNG *entry);
void Clear_fengyoung(int num, MATCHENTRY_FENGYOUNG *entry);


#ifdef __cplusplus
}
#endif

#endif /* __STRING_MATCH__PURE_C_VERSION___H_ */ 
