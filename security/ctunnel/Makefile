# $OpenBSD: Makefile,v 1.7 2021/11/17 14:13:10 tb Exp $

COMMENT=	provide cryptographic tunnel

DISTNAME=	ctunnel-0.4
CATEGORIES=	security
REVISION=	1
FIX_EXTRACT_PERMISSIONS=Yes

HOMEPAGE=	http://nardcore.org/ctunnel/

MAINTAINER=	Pierre-Emmanuel Andre <pea@openbsd.org>

# GPLv2
PERMIT_PACKAGE=	Yes

MASTER_SITES=	${HOMEPAGE}

WANTLIB= 	c crypto pthread z

NO_TEST=	Yes

USE_GMAKE=	Yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ctunnel
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ctunnel/

.include <bsd.port.mk>
