# $OpenBSD: Makefile.inc,v 1.8 2021/12/19 18:01:12 daniel Exp $

# Other architectures not fully supported yet
ONLY_FOR_ARCHS = amd64 i386 powerpc mips64

DISTVER =	20211219
PKGVER =	1.1.0.${DISTVER}
PCCVER =	1.2.0.DEVEL

# XXX: If a new release is made:
# DISTVER =	${PCCVER}
# PKGVER =	${PCCVER}
# PCCVER =	1.2.0

EXTRACT_SUFX =	.tgz

CATEGORIES ?=	lang

HOMEPAGE ?=	http://pcc.ludd.ltu.se/

# BSD
PERMIT_PACKAGE =	Yes

CONFIGURE_STYLE ?=	gnu

NO_TEST ?=		Yes
