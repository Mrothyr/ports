# $OpenBSD: Makefile.inc,v 1.4 2021/03/22 17:06:52 sthen Exp $

COMMENT=	BIRD internet routing daemon

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME:S/-/-doc-/}${EXTRACT_SUFX}

CATEGORIES=	net

HOMEPAGE=	https://bird.network.cz/

# GPLv2+
PERMIT_PACKAGE=	Yes

MASTER_SITES=	ftp://bird.network.cz/pub/bird/

DEBUG_PACKAGES=	${BUILD_PACKAGES}

BUILD_DEPENDS=	devel/m4 \
		devel/bison

USE_GMAKE=	Yes
CONFIGURE_STYLE?= gnu
MODGNU_CONFIG_GUESS_DIRS= ${WRKSRC}/tools

FAKE_FLAGS=	sysconfdir=${TRUEPREFIX}/share/examples/bird

NO_TEST=	Yes
