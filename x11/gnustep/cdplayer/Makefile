# $OpenBSD: Makefile,v 1.17 2021/10/19 19:43:36 sebastia Exp $

COMMENT =	GNUstep based CD player

VERSION =	0.5.1
REVISION =	15
DISTNAME =	cdplayer-${VERSION}

HOMEPAGE =	http://gsburn.sourceforge.net/
MASTER_SITES =	${MASTER_SITE_SOURCEFORGE:=gsburn/}
EXTRACT_SUFX =	.tar.bz2

MODULES =	x11/gnustep
WANTLIB +=	cdaudio PreferencePanes
WANTLIB += ${COMPILER_LIBCXX}
LIB_DEPENDS +=	audio/libcdaudio \
		x11/gnustep/systempreferences

WRKDIST =	${WRKDIR}/CDPlayer-${VERSION}

MAKE_FLAGS +=	prefs=sysprefs

.include <bsd.port.mk>
