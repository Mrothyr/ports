# $OpenBSD: Makefile,v 1.64 2021/12/20 11:45:28 gonzalo Exp $

COMMENT =		complete front-end for MPlayer and MPV

DISTNAME =		smplayer-21.10.0
CATEGORIES =		multimedia x11

HOMEPAGE =		https://www.smplayer.info/

MAINTAINER =		Gonzalo L. R. <gonzalo@openbsd.org>

# GPLv2 (docs/en/gpl.html)
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX}
WANTLIB += GL Qt5Core Qt5DBus Qt5Gui Qt5Network Qt5Widgets
WANTLIB += Qt5Xml X11 Xext c m pthread z

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=smplayer/}

EXTRACT_SUFX =		.tar.bz2

MODULES =		x11/qt5
RUN_DEPENDS =		devel/desktop-file-utils \
			mpv-*|mplayer->=20090708:multimedia/mpv \
			www/yt-dlp \
			x11/gtk+3,-guic

USE_GMAKE =		Yes

NO_TEST =		Yes

ALL_TARGET =		src/smplayer

MAKE_FLAGS =		QMAKE=${MODQT_QMAKE} \
			LRELEASE=${MODQT_LRELEASE}

.include <bsd.port.mk>
