# $OpenBSD: Makefile,v 1.27 2021/10/25 07:24:24 ajacoutot Exp $

PKG_ARCH=		*

COMMENT=		base icon theme for GNOME

GNOME_PROJECT=		adwaita-icon-theme
GNOME_VERSION=		41.0

CATEGORIES=		x11

# GPLv2
PERMIT_PACKAGE=		Yes

MODULES=		x11/gnome

MODGNOME_TOOLS=		gtk-update-icon-cache

CONFIGURE_ENV=		ac_cv_path_GIT=false \
			ac_cv_path_INKSCAPE=false

BUILD_DEPENDS=		x11/icontool
RUN_DEPENDS=		x11/gnome/librsvg

CONFIGURE_STYLE=	gnu

# XXX cyclic dep: gtk+3->adwaita-icon-theme->gtk+3
#BUILD_DEPENDS +=	x11/gtk+3
CONFIGURE_ENV +=	ac_cv_path_GTK_ENCODE_SYMBOLIC_SVG=false

# package takes care of running gtk-update-icon-cache (@exec)
CONFIGURE_ENV +=	ac_cv_path_GTK_UPDATE_ICON_CACHE=/usr/bin/true

# installs empty share/locale/... directories
post-install:
	rm -rf ${PREFIX}/share/locale

.include <bsd.port.mk>
