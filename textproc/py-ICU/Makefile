# $OpenBSD: Makefile,v 1.33 2022/02/25 13:54:49 ajacoutot Exp $

COMMENT=		Python extension wrapping the ICU C++ API

MODPY_EGG_VERSION=	2.8.1
DISTNAME=		PyICU-${MODPY_EGG_VERSION}
PKGNAME=		py-ICU-${MODPY_EGG_VERSION}

CATEGORIES=		textproc

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# MIT
PERMIT_PACKAGE=	Yes

WANTLIB += icudata icui18n icuuc m pthread ${COMPILER_LIBCXX}

MODULES=		lang/python

MODPY_PI=		Yes
MODPY_PYTEST=		Yes
MODPY_SETUPTOOLS=	Yes

FLAVORS=		python3
FLAVOR=			python3

COMPILER=		base-clang ports-gcc

LIB_DEPENDS=		textproc/icu4c

TEST_DEPENDS=		devel/py-six${MODPY_FLAVOR} \
			devel/py-test${MODPY_FLAVOR}

.if !${FLAVOR:Mpython3}
WANTLIB +=	${MODPY_WANTLIB}
LIB_DEPENDS +=	${MODPY_LIB_DEPENDS}
.endif

DEBUG_PACKAGES=	${BUILD_PACKAGES}

pre-configure:
	${SUBST_CMD} ${WRKSRC}/setup.py

.include <bsd.port.mk>
