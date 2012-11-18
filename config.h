/* See LICENSE file for copyright and license details. */

/* appearance */
#define NUMCOLORS 8 // need at least 3
static const char colors[NUMCOLORS][ColLast][8] = {
   // border   foreground  background
   { "#222222", "#AAAAAA", "#222222" }, // 0 = normal
   { "#0055FF", "#0055FF", "#222222" }, // 1 = selected
   { "#222222", "#BF1E2D", "#222222" }, // 2 = red
   { "#222222", "#0099CC", "#222222" }, // 3 = cyan
   { "#222222", "#93D44F", "#222222" }, // 4 = green
   { "#222222", "#0055FF", "#222222" }, // 5 = blue
   { "#222222", "#652F90", "#222222" }, // 6 = magenta
   { "#222222", "#F5B915", "#222222" }, // 7 = yellow
};

/* dwm vars */
static const char font[]            = "-*-stlarch-medium-r-*-*-10-*-*-*-*-*-*-*" "," "-*-termsyn-medium-*-*-*-11-*-*-*-*-*-iso8859-2";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */


/* tag definitions for rules */
#define WEB 1 << 0
#define MEDIA 1 << 1
#define CHAT 1 << 2

/* rules */
static const Rule rules[] = {
        /* class      instance    title       tags      isfloating   monitor */
        { "Chromium", NULL,       NULL,       WEB,      False,          -1 },
        { "Firefox",  NULL,       NULL,       WEB,      False,          -1 },
        { NULL,       NULL,       "ncmpcpp",  MEDIA,    False,          -1 },
        { NULL,       NULL,       "utub",     MEDIA,    False,          -1 },
        { NULL,       NULL,       "fmplayer", MEDIA,    False,          -1 },
        { NULL,       NULL,       "msearch",  MEDIA,    False,          -1 },
        { NULL,       NULL,       "mutt",     CHAT,     False,          -1 },
        { NULL,       NULL,       "weechat",  CHAT,     False,          -1 },
        { "qemu-system-x86_64", NULL, NULL,   0,        True,           -1 },
};

/* layout(s) */
static const float mfact      = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1; /* number of clients in master area */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */
static const Layout layouts[] = {
        /* symbol     arrange function */
        { "",      tile },    /* first entry is default */
        { "",      NULL },    /* no layout function means floating behavior */
        { "",      monocle },
         { "",      bstack },
        { .symbol = NULL,   .arrange = NULL    },
};

/* tagging */
static const Tag tags[] = {
        /* name       layout           mfact    nmaster */
        { "",        &layouts[2],     -1,      -1 },
        { "",        &layouts[2],     -1,      -1 },
        { "",        &layouts[0],     -1,      -1 },
        { "",        &layouts[0],     -1,      -1 },
        { "",        &layouts[0],     -1,      -1 },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
        { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
        { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
        { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
        { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define MOVEWITH(KEY, CMD, WORKSPACEMASK) \
        { MODKEY,                       KEY,      view,           {.ui = 1 << WORKSPACEMASK} }, \
        { MODKEY,                       KEY,      spawn,          {.v = CMD } },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[] = { "urxvtc",     NULL };
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
static const char *menucmd[] = { "buildgtkmenu.sh", NULL };
static const char *lock[] = { "xautolock", "-locknow", NULL };
static const char *power[] = { "/home/mhiggin5/programs/bash/exit.sh", NULL };
static const char *kill[] = { "killdwm", NULL };
static const char *clearnotify[] = { "killall", "-SIGUSR1", "dunst", NULL };
static const char *clearnotify2[] = { "notify-send", "notifications cleared", NULL };

/* programs */
static const char *tasknc[] = { "urxvtc", "-title", "tasknc", "-e", "/home/mhiggin5/programs/c/tasknc/tasknc", NULL };
static const char *desktop[] = { "urxvtc", "-title", "ssh", "-e", "/home/mhiggin5/programs/bash/ssh-arch-phoenix.sh", NULL };
static const char *htop[] = { "urxvtc", "-title", "htop", "-e", "htop", NULL};
static const char *mutt[] = { "/home/mhiggin5/programs/bash/launch.sh", "mutt", NULL };
static const char *chat[] = { "/home/mhiggin5/programs/bash/launch.sh","weechat", NULL };
static const char *browser[] = { "/home/mhiggin5/programs/bash/launch.sh", "chromium", NULL };
static const char *minbrowser[] = { "dwb", NULL };
static const char *fm[] = { "urxvtc", "-e", "ranger", NULL};

/* media utils */
static const char *dmenuwatchvideo[] = {"/home/mhiggin5/programs/bash/flash-video-dmenu.sh", NULL };
static const char *mediainfo[] = { "mmcs", "-y", NULL };
static const char *medianext[] = { "mmcs", "-yn", NULL };
static const char *mediaprev[] = { "mmcs", "-yp", NULL };
static const char *mediastop[] = { "mmcs", "-ys", NULL };
static const char *mediatoggle[] = { "mmcs", "-yt", NULL };
static const char *mpdnext[] = { "mmcs", "-myn", NULL };
static const char *mpdprev[] = { "mmcs", "-myp", NULL };
static const char *mpdstop[] = { "mmcs", "-mys", NULL };
static const char *mpdtoggle[] = { "mmcs", "-myt", NULL };
static const char *msearch[] = { "urxvtc", "-title", "msearch", "-e", "/home/mhiggin5/programs/python/msearch.py", "-k", NULL };
static const char *ncmpcpp[] = { "/home/mhiggin5/programs/bash/launch.sh", "ncmpcpp", NULL };
static const char *utub[] = { "urxvtc", "-title", "utub", "-e", "utub-curses", NULL };
static const char *volup[] = { "/home/mhiggin5/programs/bash/alsavol", "-i", "1", NULL };
static const char *voldn[] = { "/home/mhiggin5/programs/bash/alsavol", "-d", "1", NULL };
static const char *watchvideo[] = { "fmplayer.lua", "-b", NULL };

/* keybinds */
static Key keys[] = {
        /* modifier                     key             function             argument */
        /* general dwm control binds */
        { MODKEY|ShiftMask,             XK_t,           togglebar,      {0} },
        { MODKEY|ShiftMask,             XK_k,           killclient,     {0} },
        { Mod1Mask,                     XK_F4,          killclient,     {0} },
        { MODKEY|ShiftMask,             XK_l,           spawn,          {.v = lock } },
        { MODKEY,                       XK_Delete,      spawn,          {.v = power } },
        { MODKEY|ControlMask,           XK_q,           spawn,          {.v = kill } },
        { MODKEY|ShiftMask,             XK_q,           quit,           {0} },
        /* monitor binds */
        { MODKEY,                       XK_comma,       focusmon,       {.i = -1 } },
        { MODKEY,                       XK_period,      focusmon,       {.i = +1 } },
        { MODKEY|ShiftMask,             XK_comma,       tagmon,         {.i = -1 } },
        { MODKEY|ShiftMask,             XK_period,      tagmon,         {.i = +1 } },
        { Mod1Mask,                     XK_Tab,         focusmon,       {.i = +1 } },
        { Mod1Mask|ShiftMask,           XK_Tab,         tagmon,         {.i = +1 } },
        /* window control binds */
        { MODKEY,                       XK_j,           focusstack,     {.i = +1 } },
        { MODKEY,                       XK_k,           focusstack,     {.i = -1 } },
        { MODKEY,                       XK_h,           setmfact,       {.f = -0.05} },
        { MODKEY,                       XK_l,           setmfact,       {.f = +0.05} },
        { MODKEY|ShiftMask,             XK_Return,      zoom,           {0} },
        /* tag binds */
        TAGKEYS(                        XK_1,           0)
        TAGKEYS(                        XK_2,           1)
        TAGKEYS(                        XK_3,           2)
        TAGKEYS(                        XK_4,           3)
        TAGKEYS(                        XK_5,           4)
        { MODKEY,                       XK_Tab,         view,           {0} },
        { MODKEY,                       XK_0,           view,           {.ui = ~0 } },
        { MODKEY|ShiftMask,             XK_0,           tag,            {.ui = ~0 } },
        { MODKEY,                       XK_Left,        cycle,          {.i = -1} },
        { MODKEY,                       XK_Right,       cycle,          {.i = +1} },
        { MODKEY|ShiftMask,             XK_Left,        tagcycle,       {.i = -1} },
        { MODKEY|ShiftMask,             XK_Right,       tagcycle,       {.i = +1} },
        /* layout binds */
        { MODKEY,                       XK_t,           setlayout,      {.v = &layouts[0]} },
        { MODKEY,                       XK_f,           setlayout,      {.v = &layouts[1]} },
        { MODKEY,                       XK_m,           setlayout,      {.v = &layouts[2]} },
        { MODKEY,                       XK_space,       nextlayout,     {0} },
        { MODKEY|ShiftMask,             XK_space,       togglefloating, {0} },
        /* launcher binds */
        { MODKEY,                       XK_a,           spawn,          {.v = tasknc } },
        MOVEWITH(                       XK_g,           browser,        0)
        { MODKEY,                       XK_s,           spawn,          {.v = desktop } },
        { MODKEY,                       XK_p,           spawn,          {.v = dmenucmd } },
        { MODKEY,                       XK_q,           spawn,          {.v = htop } },
        { MODKEY,                       XK_w,           spawn,          {.v = minbrowser } },
        MOVEWITH(                       XK_e,           mutt,           2)
        { MODKEY,                       XK_Return,      spawn,          {.v = termcmd } },
        { MODKEY,                       XK_d,           spawn,          {.v = fm } },
        MOVEWITH(                       XK_i,           chat,           2)
        /* media keybinds */
        { MODKEY|ShiftMask,             XK_y,           spawn,          {.v = dmenuwatchvideo } },
        { MODKEY,                       XK_z,           spawn,          {.v = mpdprev } },
        { MODKEY,                       XK_c,           spawn,          {.v = mpdtoggle } },
        { MODKEY,                       XK_x,           spawn,          {.v = mediainfo } },
        { MODKEY,                       XK_v,           spawn,          {.v = mpdstop } },
        { MODKEY,                       XK_b,           spawn,          {.v = mpdnext } },
        { MODKEY|ShiftMask,             XK_c,           spawn,          {.v = mediatoggle } },
        { MODKEY|ShiftMask,             XK_v,           spawn,          {.v = mediastop } },
        { MODKEY|ShiftMask,             XK_z,           spawn,          {.v = mediaprev } },
        { MODKEY|ShiftMask,             XK_b,           spawn,          {.v = medianext } },
        MOVEWITH(                       XK_r,           msearch,        1)
        MOVEWITH(                       XK_n,           ncmpcpp,        1)
        MOVEWITH(                       XK_u,           utub,           1)
        { MODKEY,                       XK_Next,        spawn,          {.v = voldn } },
        { MODKEY,                       XK_Prior,       spawn,          {.v = volup } },
        { 0,                            0x1008ff11,     spawn,          {.v = voldn } },
        { 0,                            0x1008ff13,     spawn,          {.v = volup } },
        MOVEWITH(                       XK_y,           watchvideo,     1)
        { MODKEY,                       XK_grave,       spawn,          {.v = clearnotify } },
        { MODKEY,                       XK_grave,       spawn,          {.v = clearnotify2 } },
};

/* mouse binds */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
        /* click                event mask      button          function        argument */
        { ClkLtSymbol,          0,              Button1,        nextlayout,     {0} },
        { ClkLtSymbol,          0,              Button3,        prevlayout,     {0} },
        { ClkWinTitle,          0,              Button2,        zoom,           {0} },
        { ClkWinTitle,          0,              Button3,        spawn,          {.v = menucmd } },
        { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
        { ClkStatusText,        0,              Button3,        spawn,          {.v = menucmd } },
        { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
        { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
        { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
        { ClkTagBar,            0,              Button1,        view,           {0} },
        { ClkTagBar,            0,              Button3,        toggleview,     {0} },
        { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
        { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
        { ClkRootWin,           0,              Button3,        spawn,          {.v = menucmd } },
};
