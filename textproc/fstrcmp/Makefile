# $OpenBSD: Makefile,v 1.1.1.1 2021/10/08 22:34:41 thfr Exp $

COMMENT=	library for fuzzy string comparisons

DISTNAME=	fstrcmp-0.7.D001
CATEGORIES=	textproc
MASTER_SITES=	${HOMEPAGE}

SHARED_LIBS=	fstrcmp		0.0

HOMEPAGE=	http://fstrcmp.sourceforge.net/

# GPLv3
PERMIT_PACKAGE=	Yes

WANTLIB=	c

BUILD_DEPENDS+=	textproc/groff

CONFIGURE_STYLE=	gnu

.include <bsd.port.mk>
