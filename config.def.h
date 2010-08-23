/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]            = "-*-terminus-medium-r-*-*-16-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#222222";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#aaaaaa";
static const char selbordercolor[]  = "#0055ff";
static const char selbgcolor[]      = "#0055ff";
static const char selfgcolor[]      = "#aaaaaa";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "1", "2", "3", "4" };

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Chromium", NULL,       NULL,       1 << 1,       False,       -1 },
	{ NULL,       NULL,       "ncmpcpp",  1 << 2,       False,       -1 },
	{ NULL,       NULL,       "mutt",     1 << 3,       False,       -1 },
	{ NULL,       NULL,       "weechat",  1 << 3,       False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
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
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "urxvtc", NULL };
static const char *ncmpcpp[] = { "urxvtc", "-title", "ncmpcpp","-e", "ncmpcpp", NULL };
static const char *mutt[] = { "urxvtc", "-title", "mutt","-e", "mutt", NULL };
static const char *weechat[] = { "urxvtc", "-title", "weechat","-e", "weechat-curses", NULL };
static const char *chromium[] = { "chromium", NULL };
static const char *jumanji[] = { "jumanji", NULL };
static const char *mediatoggle[] = { "/home/mhiggin5/.bin/mediacontrol", "pause", NULL };
static const char *medianext[] = { "/home/mhiggin5/.bin/mediacontrol", "next", NULL };
static const char *mediaprev[] = { "/home/mhiggin5/.bin/mediacontrol", "prev", NULL };
static const char *mediastop[] = { "/home/mhiggin5/.bin/mediacontrol", "stop", NULL };
static const char *volup[] = { "/home/mhiggin5/programs/bash/ossvol", "-i", "1", NULL };
static const char *voldn[] = { "/home/mhiggin5/programs/bash/ossvol", "-d", "1", NULL };
static const char *utub[] = { "urxvtc", "-title", "utub","-e", "utub-color", NULL };
static const char *watchvideo[] = { "/home/mhiggin5/.bin/watchvideo", NULL };
static const char *suspend[] = { "/home/mhiggin5/.bin/watchvideo", NULL };
static const char *lock[] = { "slock", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ Mod1Mask,                     XK_Tab,    focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ Mod1Mask,                     XK_F4,     killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
        { MODKEY,                       XK_z,      spawn,          {.v = mediaprev } },
        { MODKEY,                       XK_c,      spawn,          {.v = mediatoggle } },
        { MODKEY,                       XK_v,      spawn,          {.v = mediastop } },
        { MODKEY,                       XK_b,      spawn,          {.v = medianext } },
        { MODKEY,                       XK_n,      spawn,          {.v = ncmpcpp } },
        { MODKEY,                       XK_e,      spawn,          {.v = mutt } },
        { MODKEY,                       XK_i,      spawn,          {.v = weechat } },
        { MODKEY,                       XK_g,      spawn,          {.v = chromium } },
        { MODKEY,                       XK_w,      spawn,          {.v = jumanji } },
        { MODKEY,                       XK_y,      spawn,          {.v = watchvideo } },
        { MODKEY,                       XK_u,      spawn,          {.v = utub } },
        { MODKEY,                       XK_l,      spawn,          {.v = lock } },
        { MODKEY,                       XK_Next,   spawn,          {.v = voldn } },
        { MODKEY,                       XK_Prior,  spawn,          {.v = volup } },
        { Mod1Mask|ControlMask,         XK_Escape, spawn,          {.v = suspend } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
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
