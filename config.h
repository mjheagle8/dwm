/* See LICENSE file for copyright and license details. */

/* appearance */
#define NUMCOLORS 8 // need at least 3
static const char colors[NUMCOLORS][ColLast][8] = {
   // border   foreground  background
   { "#222222", "#AAAAAA", "#222222" }, // 0 = normal
   { "#0055FF", "#0055FF", "#222222" }, // 1 = selected
   { "#222222", "#FF6565", "#222222" }, // 2 = red
   { "#222222", "#89B6E2", "#222222" }, // 3 = cyan
   { "#222222", "#93D44F", "#222222" }, // 4 = green
   { "#222222", "#0055FF", "#222222" }, // 5 = blue
   { "#222222", "#F57900", "#222222" }, // 6 = magenta
   { "#222222", "#EAB93D", "#222222" }, // 7 = yellow
};

static const char font[]            = "-*-terminus-medium-r-*-*-12-*-*-*-*-*-*-*";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "web", "media", "msg", "4", "5"};
static const int taglayouts[] = {2, 2, 0, 0, 0};

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Chromium", NULL,       NULL,       1 << 0,       False,       -1 },
	{ NULL,       NULL,       "ncmpcpp",  1 << 1,       False,       -1 },
	{ NULL,       NULL,       "utub",     1 << 1,       False,       -1 },
	{ NULL,       NULL,       "fmplayer", 1 << 1,       False,       -1 },
	{ NULL,       NULL,       "msearch",  1 << 1,       False,       -1 },
	{ NULL,       NULL,       "mutt",     1 << 2,       False,       -1 },
	{ NULL,       NULL,       "weechat",  1 << 2,       False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },    /* first entry is default */
	{ "[F]",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
 	{ "[B]",      bstack },
 	{ "[b]",      bstackhoriz },
        { .symbol = NULL,   .arrange = NULL    },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
static const char *termcmd[]  = { "urxvtc", NULL };
static const char *ncmpcpp[] = { "/home/mhiggin5/programs/bash/launch.sh", "ncmpcpp", NULL };
static const char *mutt[] = { "/home/mhiggin5/programs/bash/launch.sh", "mutt", NULL };
static const char *weechat[] = { "/home/mhiggin5/programs/bash/launch.sh","weechat", NULL };
static const char *chromium[] = { "/home/mhiggin5/programs/bash/launch.sh", "chromium", NULL };
static const char *mediatoggle[] = { "/home/mhiggin5/programs/c/mediactrl/mediactrl", "-t", NULL };
static const char *medianext[] = { "/home/mhiggin5/programs/c/mediactrl/mediactrl", "-n", NULL };
static const char *mediaprev[] = { "/home/mhiggin5/programs/c/mediactrl/mediactrl", "-p", NULL };
static const char *mediastop[] = { "/home/mhiggin5/programs/c/mediactrl/mediactrl", "-s", NULL };
static const char *minbrowser[] = { "luakit", NULL };
static const char *mpdtoggle[] = { "mpc", "toggle", NULL };
static const char *mpdnext[] = { "mpc", "next", NULL };
static const char *mpdprev[] = { "mpc", "prev", NULL };
static const char *mpdstop[] = { "mpc", "stop", NULL };
static const char *volup[] = { "/home/mhiggin5/programs/bash/ossvol", "-i", "1", NULL };
static const char *voldn[] = { "/home/mhiggin5/programs/bash/ossvol", "-d", "1", NULL };
static const char *utub[] = { "urxvtc", "-title", "utub", "-e", "utub-curses", NULL };
static const char *watchvideo[] = { "urxvtc", "-title", "fmplayer", "-e", "/home/mhiggin5/programs/python/flash-mplayer.py", NULL };
static const char *dmenuwatchvideo[] = {"/home/mhiggin5/programs/bash/flash-video-dmenu.sh", NULL };
static const char *power[] = { "/home/mhiggin5/programs/bash/exit.sh", NULL };
static const char *lock[] = { "slock", NULL };
static const char *kill[] = { "/home/mhiggin5/programs/bash/killdwm", NULL };
static const char *desktop[] = { "urxvtc", "-title", "ssh", "-e", "/home/mhiggin5/programs/bash/ssh-arch-phoenix.sh", NULL };
static const char *msearch[] = { "urxvtc", "-title", "msearch", "-e", "/home/mhiggin5/programs/python/msearch.py", "-k", NULL };
static const char *transdown[] = { "transset-df", "-p", "--min", "0.2", "--dec", "0.1", NULL };
static const char *transup[] = { "transset-df", "-p", "--inc", "0.1", NULL };
static const char *compositing[] = { "compositing", "toggle", NULL };
static const char *vifm[] = { "urxvtc", "-e", "vifm", NULL};

static Key keys[] = {
	/* modifier                     key             function             argument */
	{ MODKEY,                       XK_p,           spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return,      spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_t,           togglebar,      {0} },
	{ MODKEY,                       XK_j,           focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,           focusstack,     {.i = -1 } },
	{ Mod1Mask,                     XK_Tab,         focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_h,           setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,           setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return,      zoom,           {0} },
	{ MODKEY,                       XK_Tab,         view,           {0} },
	{ MODKEY|ShiftMask,             XK_k,           killclient,     {0} },
	{ Mod1Mask,                     XK_F4,          killclient,     {0} },
	{ MODKEY,                       XK_t,           setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,           setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,           setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,       nextlayout,     {0} },
	{ MODKEY|ShiftMask,             XK_space,       togglefloating, {0} },
	{ MODKEY,                       XK_0,           view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,           tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,       focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,      focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,       tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,      tagmon,         {.i = +1 } },
        { MODKEY,                       XK_z,           spawn,          {.v = mediaprev } },
        { MODKEY,                       XK_c,           spawn,          {.v = mediatoggle } },
        { MODKEY,                       XK_v,           spawn,          {.v = mediastop } },
        { MODKEY,                       XK_b,           spawn,          {.v = medianext } },
        { MODKEY|ShiftMask,             XK_z,           spawn,          {.v = mpdprev } },
        { MODKEY|ShiftMask,             XK_c,           spawn,          {.v = mpdtoggle } },
        { MODKEY|ShiftMask,             XK_v,           spawn,          {.v = mpdstop } },
        { MODKEY|ShiftMask,             XK_b,           spawn,          {.v = mpdnext } },
        { MODKEY,                       XK_n,           spawn,          {.v = ncmpcpp } },
	{ MODKEY,                       XK_n,           view,           {.ui = 1 << 1} }, 
        { MODKEY,                       XK_e,           spawn,          {.v = mutt } },
	{ MODKEY,                       XK_e,           view,           {.ui = 1 << 2} }, 
        { MODKEY,                       XK_i,           spawn,          {.v = weechat } },
	{ MODKEY,                       XK_i,           view,           {.ui = 1 << 2} }, 
        { MODKEY,                       XK_g,           spawn,          {.v = chromium } },
	{ MODKEY,                       XK_g,           view,           {.ui = 1 << 0} }, 
        { MODKEY|ShiftMask,             XK_y,           spawn,          {.v = dmenuwatchvideo } },
        { MODKEY,                       XK_y,           spawn,          {.v = watchvideo } },
	{ MODKEY,                       XK_y,           view,           {.ui = 1 << 1} }, 
        { MODKEY,                       XK_u,           spawn,          {.v = utub } },
	{ MODKEY,                       XK_u,           view,           {.ui = 1 << 1} }, 
        { MODKEY|ShiftMask,             XK_l,           spawn,          {.v = lock } },
        { MODKEY,                       XK_Next,        spawn,          {.v = voldn } },
        { MODKEY,                       XK_Prior,       spawn,          {.v = volup } },
        { 0,                            0x1008ff11,     spawn,          {.v = voldn } },
        { 0,                            0x1008ff13,     spawn,          {.v = volup } },
        { MODKEY,                       XK_Delete,      spawn,          {.v = power } },
        { MODKEY,                       XK_s,           spawn,          {.v = desktop } },
        { MODKEY,                       XK_d,           spawn,          {.v = vifm } },
        { MODKEY,                       XK_r,           spawn,          {.v = msearch } },
	{ MODKEY,                       XK_r,           view,           {.ui = 1 << 1} }, 
	{ MODKEY,                       XK_w,           spawn,          {.v = minbrowser } },
	TAGKEYS(                        XK_1,           0)
	TAGKEYS(                        XK_2,           1)
	TAGKEYS(                        XK_3,           2)
	TAGKEYS(                        XK_4,           3)
	TAGKEYS(                        XK_5,           4)
	{ MODKEY|ShiftMask,             XK_q,           quit,           {0} },
	{ MODKEY|ControlMask,           XK_q,           spawn,          {.v = kill } },
	{ MODKEY,                       XK_Down,        spawn,          {.v = transdown } },
	{ MODKEY,                       XK_Up,          spawn,          {.v = transup } },
	{ MODKEY,                       XK_o,           spawn,          {.v = compositing } },
        { MODKEY,                       XK_Left,        cycle,          {.i = -1} },
        { MODKEY,                       XK_Right,       cycle,          {.i = +1} },
        { MODKEY|ShiftMask,             XK_Left,        tagcycle,       {.i = -1} },
        { MODKEY|ShiftMask,             XK_Right,       tagcycle,       {.i = +1} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        nextlayout,     {0} },
	{ ClkLtSymbol,          0,              Button3,        prevlayout,     {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
