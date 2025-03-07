# $OpenBSD: Makefile,v 1.181 2021/11/02 00:00:14 sthen Exp $

COMMENT=		integrated music management application for GNOME

GNOME_PROJECT=		rhythmbox
GNOME_VERSION=		3.4.4
REVISION=		3

SHARED_LIBS +=  rhythmbox-core       0.0      # 7.0

CATEGORIES=		audio

MAINTAINER=		Jasper Lievisse Adriaanse <jasper@openbsd.org>, \
			Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2 with exception clause
PERMIT_PACKAGE=	Yes

WANTLIB += X11 Xcomposite Xcursor Xdamage Xext Xfixes Xi Xinerama
WANTLIB += Xrandr Xrender archive atk-1.0 atk-bridge-2.0 b2 brotlicommon
WANTLIB += brotlidec bz2 c cairo cairo-gobject charset crypto
WANTLIB += epoxy expat ffi fontconfig freetype fribidi gcrypt
WANTLIB += gdk-3 gdk_pixbuf-2.0 gio-2.0 girepository-1.0 glib-2.0
WANTLIB += gmodule-2.0 gobject-2.0 gpg-error graphite2 grilo-0.3
WANTLIB += gstaudio-1.0 gstbase-1.0 gstcontroller-1.0 gstpbutils-1.0
WANTLIB += gstreamer-1.0 gsttag-1.0 gstvideo-1.0 gtk-3 harfbuzz
WANTLIB += iconv idn2 intl json-glib-1.0 lz4 lzma m notify orc-0.4
WANTLIB += pango-1.0 pangocairo-1.0 pangoft2-1.0 pcre peas-1.0
WANTLIB += peas-gtk-1.0 pixman-1 png psl pthread soup-2.4 sqlite3
WANTLIB += tdb totem-plparser unistring xcb xcb-render xcb-shm
WANTLIB += xml2 z zstd

MODULES=		devel/dconf \
			lang/python \
			x11/gnome

BUILD_DEPENDS=		devel/py-gobject3${MODPY_FLAVOR}
RUN_DEPENDS=		devel/py-gobject3${MODPY_FLAVOR}

# needed for the tests
BUILD_DEPENDS +=	devel/check

LIB_DEPENDS=		databases/tdb \
			devel/json-glib \
			devel/libnotify \
			devel/libpeas \
			multimedia/gstreamer1/plugins-base \
			x11/gnome/grilo \
			x11/gnome/totem-pl-parser

# context plugin
RUN_DEPENDS +=		www/py-mako${MODPY_FLAVOR}

# calls grl_registry_load...plugin
RUN_DEPENDS +=		x11/gnome/grilo-plugins>=0.3.0

# needed for flac support
RUN_DEPENDS +=		multimedia/gstreamer1/plugins-good

# needed for mp3 support
RUN_DEPENDS +=		multimedia/gstreamer1/plugins-libav

MODGNOME_TOOLS += desktop-file-utils gobject-introspection gtk-update-icon-cache
MODGNOME_TOOLS += vala yelp

MODGNOME_LDFLAGS=	-L${X11BASE}/lib
MODGNOME_CPPFLAGS=	-I${X11BASE}/include

CONFIGURE_STYLE= 	gnu
CONFIGURE_ARGS=		--without-brasero \
			--without-hal \
			--without-gudev \
			--without-ipod \
			--disable-fm-radio \
			--disable-lirc

# XXX requires libdmapsharing
CONFIGURE_ARGS +=	--disable-daap

# XXX requires hal|udev|gvfs-mtp
CONFIGURE_ARGS +=	--without-mtp

# XXX requires libmx
CONFIGURE_ARGS +=	--disable-visualizer

# WRKBUILD/tests
TEST_IS_INTERACTIVE=	x11

post-install:
	rm ${PREFIX}/lib/rhythmbox/{,sample-}plugins/*/*.la
	rm ${PREFIX}/lib/rhythmbox/sample-plugins/*/*.a
	# XXX hangs: check at next rhythmbox update
	rm -rf ${PREFIX}/{lib,share}/rhythmbox/plugins/replaygain

.include <bsd.port.mk>
