#
# Regular cron jobs for the dvdcopy package
#
0 4	* * *	root	[ -x /usr/bin/dvdcopy_maintenance ] && /usr/bin/dvdcopy_maintenance
