#if 0
	shc Version 3.8.9, Generic Script Compiler
	Copyright (c) 1994-2012 Francisco Rosales <frosal@fi.upm.es>

	shc -f ola.sh 
#endif

static  char data [] = 
#define      inlo_z	3
#define      inlo	((&data[0]))
	"\320\060\346"
#define      rlax_z	1
#define      rlax	((&data[3]))
	"\337"
#define      xecc_z	15
#define      xecc	((&data[7]))
	"\252\340\102\355\030\305\174\322\301\251\373\277\256\020\043\007"
	"\062\042\270\344\206"
#define      chk1_z	22
#define      chk1	((&data[27]))
	"\210\015\317\023\202\025\207\314\151\117\337\220\012\212\273\261"
	"\244\016\106\257\065\140\172\370\104\370\066\231"
#define      msg1_z	42
#define      msg1	((&data[60]))
	"\373\157\336\201\042\010\365\175\142\143\151\047\201\131\113\373"
	"\205\162\013\377\344\133\342\037\321\157\156\360\257\011\325\306"
	"\022\142\201\167\343\143\316\126\167\062\366\140\133\030\146\076"
	"\242\354\361\036\307\014"
#define      chk2_z	19
#define      chk2	((&data[110]))
	"\225\060\147\242\131\350\001\361\347\074\316\167\004\101\370\057"
	"\145\075\007\313\374\310\050\334\357\162"
#define      shll_z	14
#define      shll	((&data[133]))
	"\254\106\271\101\060\027\300\331\126\111\056\002\265\253"
#define      lsto_z	1
#define      lsto	((&data[147]))
	"\125"
#define      tst1_z	22
#define      tst1	((&data[150]))
	"\221\316\227\142\015\062\355\071\205\254\165\070\151\041\275\220"
	"\041\361\023\241\201\251\267\052\110\154"
#define      tst2_z	19
#define      tst2	((&data[178]))
	"\034\025\307\042\156\016\206\110\311\202\247\062\142\047\175\350"
	"\236\275\256\036\255\071\122\010\367\367"
#define      opts_z	1
#define      opts	((&data[200]))
	"\315"
#define      pswd_z	256
#define      pswd	((&data[233]))
	"\270\212\350\053\014\333\370\001\274\120\206\121\112\043\365\241"
	"\032\224\146\033\220\335\362\267\005\121\204\342\166\254\276\327"
	"\246\073\314\174\153\312\262\244\231\206\053\000\034\154\005\015"
	"\226\261\143\326\026\262\220\302\251\047\376\054\247\025\164\275"
	"\126\072\366\311\222\133\016\232\162\030\303\261\015\303\264\354"
	"\330\244\064\005\161\230\127\171\003\052\205\363\234\165\050\367"
	"\134\335\263\072\160\036\026\106\200\212\366\041\034\075\372\215"
	"\070\122\150\337\272\357\347\366\250\375\344\242\104\240\163\263"
	"\175\111\203\333\231\237\077\334\161\031\116\035\301\035\321\156"
	"\300\325\125\214\042\117\141\276\004\111\046\302\145\157\143\222"
	"\271\377\014\034\342\215\011\072\307\003\314\151\226\163\015\223"
	"\243\355\327\071\001\126\124\235\162\066\314\136\060\223\170\302"
	"\362\360\351\310\327\146\341\013\144\046\360\315\307\160\337\263"
	"\247\205\242\216\004\061\044\346\035\354\143\136\047\144\234\003"
	"\103\033\265\256\262\313\216\273\271\321\233\045\373\031\212\062"
	"\227\310\275\354\023\304\113\271\012\163\201\135\356\336\200\051"
	"\103\375\374\071\275\065\362\055\253\371\156\333\374\004\050\001"
	"\101\053\040\045\100\363\277\071\062\132\200\226\173\326\211\141"
	"\323\013\232\102\175\033\075\070\366\253\332\147\214\122\331\326"
	"\373\050\331\044\172\325\261\360\200\236\034\346\256\157\004\140"
	"\170\344\136\147\035\254\341\177\025\017\365\271\134\017"
#define      msg2_z	19
#define      msg2	((&data[536]))
	"\021\271\335\054\372\331\104\006\221\276\325\201\162\101\011\232"
	"\201\371\175\206\146"
#define      date_z	1
#define      date	((&data[556]))
	"\260"
#define      text_z	27
#define      text	((&data[557]))
	"\246\056\213\303\146\327\337\252\210\215\144\127\011\166\251\147"
	"\116\141\043\266\170\042\055\057\157\110\173\325"/* End of data[] */;
#define      hide_z	4096
#define DEBUGEXEC	0 	/* Define as 1 to debug execvp calls */
#define TRACEABLE	1	/* Define as 1 to enable ptrace the executable */

/* rtc.c */

#include <sys/stat.h>
#include <sys/types.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/* 'Alleged RC4' */

static unsigned char stte[256], indx, jndx, kndx;

/*
 * Reset arc4 stte. 
 */
void stte_0(void)
{
	indx = jndx = kndx = 0;
	do {
		stte[indx] = indx;
	} while (++indx);
}

/*
 * Set key. Can be used more than once. 
 */
void key(void * str, int len)
{
	unsigned char tmp, * ptr = (unsigned char *)str;
	while (len > 0) {
		do {
			tmp = stte[indx];
			kndx += tmp;
			kndx += ptr[(int)indx % len];
			stte[indx] = stte[kndx];
			stte[kndx] = tmp;
		} while (++indx);
		ptr += 256;
		len -= 256;
	}
}

/*
 * Crypt data. 
 */
void arc4(void * str, int len)
{
	unsigned char tmp, * ptr = (unsigned char *)str;
	while (len > 0) {
		indx++;
		tmp = stte[indx];
		jndx += tmp;
		stte[indx] = stte[jndx];
		stte[jndx] = tmp;
		tmp += stte[indx];
		*ptr ^= stte[tmp];
		ptr++;
		len--;
	}
}

/* End of ARC4 */

/*
 * Key with file invariants. 
 */
int key_with_file(char * file)
{
	struct stat statf[1];
	struct stat control[1];

	if (stat(file, statf) < 0)
		return -1;

	/* Turn on stable fields */
	memset(control, 0, sizeof(control));
	control->st_ino = statf->st_ino;
	control->st_dev = statf->st_dev;
	control->st_rdev = statf->st_rdev;
	control->st_uid = statf->st_uid;
	control->st_gid = statf->st_gid;
	control->st_size = statf->st_size;
	control->st_mtime = statf->st_mtime;
	control->st_ctime = statf->st_ctime;
	key(control, sizeof(control));
	return 0;
}

#if DEBUGEXEC
void debugexec(char * sh11, int argc, char ** argv)
{
	int i;
	fprintf(stderr, "shll=%s\n", sh11 ? sh11 : "<null>");
	fprintf(stderr, "argc=%d\n", argc);
	if (!argv) {
		fprintf(stderr, "argv=<null>\n");
	} else { 
		for (i = 0; i <= argc ; i++)
			fprintf(stderr, "argv[%d]=%.60s\n", i, argv[i] ? argv[i] : "<null>");
	}
}
#endif /* DEBUGEXEC */

void rmarg(char ** argv, char * arg)
{
	for (; argv && *argv && *argv != arg; argv++);
	for (; argv && *argv; argv++)
		*argv = argv[1];
}

int chkenv(int argc)
{
	char buff[512];
	unsigned long mask, m;
	int l, a, c;
	char * string;
	extern char ** environ;

	mask  = (unsigned long)&chkenv;
	mask ^= (unsigned long)getpid() * ~mask;
	sprintf(buff, "x%lx", mask);
	string = getenv(buff);
#if DEBUGEXEC
	fprintf(stderr, "getenv(%s)=%s\n", buff, string ? string : "<null>");
#endif
	l = strlen(buff);
	if (!string) {
		/* 1st */
		sprintf(&buff[l], "=%lu %d", mask, argc);
		putenv(strdup(buff));
		return 0;
	}
	c = sscanf(string, "%lu %d%c", &m, &a, buff);
	if (c == 2 && m == mask) {
		/* 3rd */
		rmarg(environ, &string[-l - 1]);
		return 1 + (argc - a);
	}
	return -1;
}

#if !TRACEABLE

#define _LINUX_SOURCE_COMPAT
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void untraceable(char * argv0)
{
	char proc[80];
	int pid, mine;

	switch(pid = fork()) {
	case  0:
		pid = getppid();
		/* For problematic SunOS ptrace */
#if defined(__FreeBSD__)
		sprintf(proc, "/proc/%d/mem", (int)pid);
#else
		sprintf(proc, "/proc/%d/as",  (int)pid);
#endif
		close(0);
		mine = !open(proc, O_RDWR|O_EXCL);
		if (mine) {
			kill(pid, SIGCONT);
		} else {
			perror(argv0);
			kill(pid, SIGKILL);
		}
		_exit(mine);
	case -1:
		break;
	default:
		if (pid == waitpid(pid, 0, 0))
			return;
	}
	perror(argv0);
	_exit(1);
}
#endif /* !TRACEABLE */

char * xsh(int argc, char ** argv)
{
	char * scrpt;
	int ret, i, j;
	char ** varg;
	char * me = getenv("_");
	if (me == NULL) { me = argv[0]; }

	stte_0();
	 key(pswd, pswd_z);
	arc4(msg1, msg1_z);
	arc4(date, date_z);
	if (date[0] && (atoll(date)<time(NULL)))
		return msg1;
	arc4(shll, shll_z);
	arc4(inlo, inlo_z);
	arc4(xecc, xecc_z);
	arc4(lsto, lsto_z);
	arc4(tst1, tst1_z);
	 key(tst1, tst1_z);
	arc4(chk1, chk1_z);
	if ((chk1_z != tst1_z) || memcmp(tst1, chk1, tst1_z))
		return tst1;
	ret = chkenv(argc);
	arc4(msg2, msg2_z);
	if (ret < 0)
		return msg2;
	varg = (char **)calloc(argc + 10, sizeof(char *));
	if (!varg)
		return 0;
	if (ret) {
		arc4(rlax, rlax_z);
		if (!rlax[0] && key_with_file(shll))
			return shll;
		arc4(opts, opts_z);
		arc4(text, text_z);
		arc4(tst2, tst2_z);
		 key(tst2, tst2_z);
		arc4(chk2, chk2_z);
		if ((chk2_z != tst2_z) || memcmp(tst2, chk2, tst2_z))
			return tst2;
		/* Prepend hide_z spaces to script text to hide it. */
		scrpt = malloc(hide_z + text_z);
		if (!scrpt)
			return 0;
		memset(scrpt, (int) ' ', hide_z);
		memcpy(&scrpt[hide_z], text, text_z);
	} else {			/* Reexecute */
		if (*xecc) {
			scrpt = malloc(512);
			if (!scrpt)
				return 0;
			sprintf(scrpt, xecc, me);
		} else {
			scrpt = me;
		}
	}
	j = 0;
	varg[j++] = argv[0];		/* My own name at execution */
	if (ret && *opts)
		varg[j++] = opts;	/* Options on 1st line of code */
	if (*inlo)
		varg[j++] = inlo;	/* Option introducing inline code */
	varg[j++] = scrpt;		/* The script itself */
	if (*lsto)
		varg[j++] = lsto;	/* Option meaning last option */
	i = (ret > 1) ? ret : 0;	/* Args numbering correction */
	while (i < argc)
		varg[j++] = argv[i++];	/* Main run-time arguments */
	varg[j] = 0;			/* NULL terminated array */
#if DEBUGEXEC
	debugexec(shll, j, varg);
#endif
	execvp(shll, varg);
	return shll;
}

int main(int argc, char ** argv)
{
#if DEBUGEXEC
	debugexec("main", argc, argv);
#endif
#if !TRACEABLE
	untraceable(argv[0]);
#endif
	argv[1] = xsh(argc, argv);
	fprintf(stderr, "%s%s%s: %s\n", argv[0],
		errno ? ": " : "",
		errno ? strerror(errno) : "",
		argv[1] ? argv[1] : "<null>"
	);
	return 1;
}
