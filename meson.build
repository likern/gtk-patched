project('gtk+-3.0', 'c',
        version: '3.22.0',
        default_options: [
          'buildtype=debugoptimized',
          'c_std=gnu89',
          'warning_level=1'
        ],
        license: 'LGPLv2.1+')

gnome = import('gnome')

add_global_arguments('-DG_LOG_USE_STRUCTURED=1', language: 'c')
add_global_arguments('-DG_ENABLE_DEBUG', language: 'c')
add_global_arguments('-DG_ENABLE_CONSISTENCY_CHECKS', language: 'c')

gtk_version = meson.project_version().split('.')
gtk_major_version = gtk_version[0]
gtk_minor_version = gtk_version[1]
gtk_micro_version = gtk_version[2]
gtk_interface_age = 0
add_global_arguments('-DGTK_VERSION="' + meson.project_version() + '"', language: 'c')

# Define a string for the earliest version that this release has
# backwards binary compatibility with for all interfaces a module
# might. Unless we add module-only API with lower stability
# guarantees, this should be unchanged until we break binary compat
# for GTK+.
gtk_binary_version = '3.0.0'

gtk_binary_age = 100 * gtk_minor_version.to_int() + gtk_micro_version.to_int()
gtk_api_version = '@0@.0'.format(gtk_major_version)

x11_enabled      = get_option('enable-x11-backend')
wayland_enabled  = get_option('enable-wayland-backend')
broadway_enabled = get_option('enable-broadway-backend')


mkmarshal = find_program('build_marshal.py')
glib_marshal = find_program('glib-genmarshal')
mkenum = find_program('build_enum.py')
perl = find_program('perl')
glib_mkenums = find_program('glib-mkenums')

os_unix   = false
os_linux  = false
os_win32  = false
os_darwin = false

if host_machine.system().contains('darwin')
  os_darwin = true
elif host_machine.system().contains('mingw')
  os_win32 = true
elif host_machine.system().contains('linux')
  os_linux = true
endif

os_unix = not os_win32

build_font_demo = false




cc = meson.get_compiler('c')
cdata = configuration_data()
cdata.set('PACKAGE_VERSION', '"'+meson.project_version()+'"')
cdata.set('GTK_LOCALEDIR', '"'+get_option('localedir')+'"')
cdata.set('GTK_DATADIR', '"'+get_option('datadir')+'"')
cdata.set('GTK_LIBDIR', '"'+get_option('libdir')+'"')
cdata.set('GTK_MAJOR_VERSION', gtk_major_version)
cdata.set('GTK_MINOR_VERSION', gtk_minor_version)
cdata.set('GTK_MICRO_VERSION', gtk_micro_version)
cdata.set('GTK_BINARY_AGE', gtk_binary_age)
cdata.set('GTK_INTERFACE_AGE', gtk_interface_age)
check_headers = [
  ['HAVE_CRT_EXTERNS_H', 'crt/externs.h'],
  ['HAVE_DLFCN_H', 'dlfcn.h'],
  ['HAVE_FTW_H', 'ftw.h'],
  ['HAVE_INTTYPES_H', 'inttypes.h'],
  ['HAVE_LOCALE_H', 'locale.h'],
  ['HAVE_MEMORY_H', 'memory.h'],
  ['HAVE_STDINT_H', 'stdint.h'],
  ['HAVE_STDLIB_H', 'stdlib.h'],
  ['HAVE_STRINGS_H', 'strings.h'],
  ['HAVE_STRING_H', 'string.h'],
  ['HAVE_SYS_MMAN_H', 'sys/mman.h'],
  ['HAVE_SYS_PARAM_H', 'sys/param.h'],
  ['HAVE_SYS_STAT_H', 'sys/stat.h'],
  ['HAVE_SYS_SYSINFO_H', 'sys/sysinfo.h'],
  ['HAVE_SYS_SYSTEMINFO_H', 'sys/systeminfo.h'],
  ['HAVE_SYS_TIME_H', 'sys/time.h'],
  ['HAVE_SYS_TYPES_H', 'sys/types.h'],
  ['HAVE_UNISTD_H', 'unistd.h'],
  ['HAVE_LINUX_MEMFD_H', 'linux/memfd.h']
]

foreach h : check_headers
  if cc.has_header(h.get(1))
    cdata.set(h.get(0), 1)
  endif
endforeach

check_functions = [
# check token HAVE_BIND_TEXTDOMAIN_CODESET
# check token HAVE_COLORD
# check token HAVE_CUPS_API_1_6
  ['HAVE_DCGETTEXT', 'dcgettext', '#include<libintl.h>'],
  ['HAVE_DECL_ISINF', 'isinf', '#include<math.h>'],
  ['HAVE_DECL_ISNAN', 'isnan', '#include<math.h>'],
  ['HAVE_GETPAGESIZE', 'getpagesize', '#include<unistd.h>'],
  ['HAVE_GETRESUID', 'getresuid', '#include<unistd.h>'],
# check token HAVE_GETTEXT
# check token HAVE_GIO_UNIX
# check token HAVE_GNU_FTW
# check token HAVE_HTTPGETAUTHSTRING
# check token HAVE_HTTP_AUTHSTRING
# check token HAVE_IPRINTDIALOGCALLBACK
# check token HAVE_LC_MESSAGES
# check token HAVE_LIBM
# check token HAVE_LOCALTIME_R
  ['HAVE_LSTAT', 'lstat', '#include<sys/stat.h>'],
# check token HAVE_MALLINFO
# check token HAVE_MKSTEMP
  ['HAVE_MMAP', 'mmap', '#include<sys/mman.h>'],
  ['HAVE_NEARBYINT', 'nearbyint', '#include<math.h>'],
# check token HAVE_PAPI
# check token HAVE_POSIX_FALLOCATE
# check token HAVE_RANDR
# check token HAVE_RANDR15
  ['HAVE_ROUND', 'round', '#include<math.h>'],
  ['HAVE_RINT', 'rint', '#include<math.h>'],
  ['HAVE_LOG2', 'log2', '#include<math.h>'],
  ['HAVE_EXP2', 'exp2', '#include<math.h>'],
  ['HAVE_SINCOS', 'sincos', '#include<math.h>'],
# check token HAVE_SINCOS
# check token HAVE_SOCKADDR_UN_SUN_LEN
# check token HAVE_SOLARIS_XINERAMA
# check token HAVE_XCOMPOSITE
# check token HAVE_XCURSOR
# check token HAVE_XDAMAGE
# check token HAVE_XFIXES
# check token HAVE_XFREE_XINERAMA
# check token HAVE_XGENERICEVENTS
# check token HAVE_XINERAMA
# check token HAVE_XKB
# check token HAVE_XSYNC
# check token HAVE__NL_MEASUREMENT_MEASUREMENT
# check token HAVE__NL_PAPER_HEIGHT
# check token HAVE__NL_PAPER_WIDTH
# check token HAVE__NL_TIME_FIRST_WEEKDAY
# check token HAVE__NSGETENVIRON
]

foreach f : check_functions
  if cc.has_function(f.get(1), prefix : f.get(2))
    cdata.set(f.get(0), 1)
  endif
endforeach

cdata.set('GETTEXT_PACKAGE', '"gtk-3.0"')
cdata.set('HAVE_XSYNC', 1)
cdata.set('XINPUT_2', 1)
cdata.set('XINPUT_2_2', 1)
cdata.set('HAVE_XKB', 1)
cdata.set('HAVE_XDAMAGE', 1)
cdata.set('HAVE_XCURSOR', 1)
cdata.set('HAVE_XGENERICEVENTS', 1)
cdata.set('HAVE_RANDR', 1)

confinc = include_directories('.')
gdkinc = include_directories('gdk')
gtkinc = include_directories('gtk')

x11_dep        = dependency('x11')
xrender_dep    = dependency('xrender')
xi_dep         = dependency('xi')
xext_dep       = dependency('xext')
xcursor_dep    = dependency('xcursor')
xdamage_dep    = dependency('xdamage')
xfixes_dep     = dependency('xfixes')
xcomposite_dep = dependency('xcomposite')
glib_dep       = dependency('glib-2.0', version: '>= 2.49.4')
giounix_dep    = dependency('gio-unix-2.0', required : false)
pango_dep      = dependency('pango', version: '>=1.37.3')
pangoft_dep    = dependency('pangoft2', required: wayland_enabled or x11_enabled)
cairo_dep      = dependency('cairo', version: '>= 1.14.0')
pangocairo_dep = dependency('pangocairo')
cairogobj_dep  = dependency('cairo-gobject')
pixbuf_dep     = dependency('gdk-pixbuf-2.0', version: '>= 2.30.0')
epoxy_dep      = dependency('epoxy', version: '>= 1.0')
atk_dep        = dependency('atk', version: '>= 2.15.1')
atkbridge_dep  = dependency('atk-bridge-2.0')
gmodule_dep    = dependency('gmodule-2.0')
mlib           = cc.find_library('m')
shmlib         = cc.find_library('rt')
fontconfig_dep = dependency('fontconfig')
xkbdep         = dependency('xkbcommon', version: '>= 0.2.0')
wlclientdep    = dependency('wayland-client', version:  '>= 1.9.91')
wlprotocolsdep = dependency('wayland-protocols', version: '>= 1.7')
wlcursordep    = dependency('wayland-cursor', version: '>= 1.9.91')
wlegldep       = dependency('wayland-egl')
xrandr_dep     = dependency('xrandr')


harfbuzz_dep   = dependency('harfbuzz', version: '>= 0.9', required: false)
build_font_demo = harfbuzz_dep.found() and pangoft_dep.found()

if giounix_dep.found()
  cdata.set('HAVE_GIO_UNIX', 1)
endif

configure_file(
  input : 'config.h.meson',
  output: 'config.h',
  configuration: cdata
)

subdir('gdk')
subdir('gtk')
subdir('demos')
subdir('tests')
subdir('testsuite')
subdir('examples')