You also could view this doc from svn in doc directory.

## Features ##

  * Configure the ipsec-based VPN easily.
  * Monitor the status when the VPN server is running.
  * Monitor the traffic when connecting.
  * Decode the ESP packet.(TBD)

## TODO ##

  * racoon.conf file analyzing, classify general options and advanced options.
> The gerneral options should be used frequently and advanced option don't change ofen.

  * The GUI's design with glade,configuring and Monitoring interface, should be in different tabs.

> a) When in Configuring interface, user could:

> o Two seperated tabs for Server and Client mode, need to check what's the difference between the two modes, some option could use same controls.

> o Let user view a simple interface with the general option, also they could configure advanced option with another pop interface, such as a dialog.

> o Tooltips collect, some terminology is very hard to understand, so we need a understandable tooltips to help user's configuration.

> b) When in Monitoring interface, user could:

> o The error log of Server and Client, such as wrong configuration.

> o The log of connection when in Server mode, could view the connected client's information, such as client ip, connection time, etc.

  * Connect and disconnect interface for client, such as button, menu.
  * Start and Stop interface for server, such as button, menu.

  * Let application running from YaST (just for SUSE release).

> o Should be in the "Network Services" Group, just for Server configuration.

  * The ncurse interface in terminal.

> o It's same with the GUI, need learn about the ncurse api.

## Note ##

  * Need sudo permission to run the application, we need run the racoon daemon in root permission, also set the DNS, ip address when using in client mode.

  * Provide the "--client, --server and --monitor" parameter for this program so that user could decide the running mode.

## References ##

**http://www.netbsd.org/docs/network/ipsec/rasvpn.html**

**http://www.gtk.org/**

**http://www.gnu.org/software/ncurses/**

