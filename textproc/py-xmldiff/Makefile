# $OpenBSD: Makefile,v 1.15 2021/11/16 08:21:09 sthen Exp $

COMMENT=		show differences between XML files/DOM trees

MODPY_EGG_VERSION=	2.4
DISTNAME=		xmldiff-${MODPY_EGG_VERSION}
PKGNAME=		py-xmldiff-${MODPY_EGG_VERSION}
CATEGORIES=		textproc

HOMEPAGE=		https://github.com/Shoobx/xmldiff

# MIT
PERMIT_PACKAGE=	Yes

MODULES=		lang/python

MODPY_PI=		Yes
MODPY_SETUPTOOLS=	Yes
MODPY_PYTEST =		Yes

RUN_DEPENDS=		devel/py-six${MODPY_FLAVOR} \
			textproc/py-lxml${MODPY_FLAVOR}

.include <bsd.port.mk>
