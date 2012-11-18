#!/usr/bin/env lua
-- wrapper to run dwm
-- by mjheagle

-- settings
local pidfile = os.getenv('HOME') .. '/tmp/.dwm_pid'
local logfile = os.getenv('HOME') .. '/tmp/.dwm_log'
local dwmcmd = 'dwm'

require 'posix'

-- write pid of this script to file
local pid = posix.getpid().pid
local pfd = io.open(pidfile, 'w')
pfd:write(pid)
pfd:close()

-- run dwm in loop
while true do
    local log = io.open(logfile, 'a')
    local cmd = io.popen(dwmcmd)
    while true do
        local line = cmd:read("*l")
        if not line then break end
        print(line)
        log:write(line)
    end
end
