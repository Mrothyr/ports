# $OpenBSD: Makefile,v 1.12 2021/08/25 12:05:51 robert Exp $

COMMENT=		MATE keyboard configuration library

MATE_PROJECT=		libmatekbd

SHARED_LIBS +=  matekbd                   6.0 # 6.0
SHARED_LIBS +=  matekbdui                 6.0 # 6.0

CATEGORIES=		devel

# LGPLv2
PERMIT_PACKAGE=	Yes

WANTLIB += X11 Xcomposite Xcursor Xdamage Xext Xfixes Xi Xinerama Xrandr
WANTLIB += Xrender atk-1.0 atk-bridge-2.0 cairo cairo-gobject epoxy
WANTLIB += expat ffi fontconfig freetype fribidi gdk-3 gdk_pixbuf-2.0
WANTLIB += gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0 graphite2
WANTLIB += gtk-3 harfbuzz iconv intl lzma m pango-1.0
WANTLIB += pangocairo-1.0 pangoft2-1.0 pcre pixman-1 png pthread xcb
WANTLIB += xcb-render xcb-shm xkbfile xkbfile xklavier xml2 z
WANTLIB += ${COMPILER_LIBCXX} execinfo jpeg

MODULES=		devel/dconf \
			x11/gnome

LIB_DEPENDS=		x11/gnome/libxklavier \
			x11/gtk+3

MODGNOME_TOOLS=		gobject-introspection

CONFIGURE_STYLE=	gnu

.include <bsd.port.mk>
