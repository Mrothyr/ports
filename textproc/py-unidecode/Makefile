# $OpenBSD: Makefile,v 1.22 2022/02/28 12:47:50 sthen Exp $

COMMENT =		US-ASCII transliterations of Unicode text

MODPY_EGG_VERSION =	1.3.3
DISTNAME =		Unidecode-${MODPY_EGG_VERSION}
PKGNAME =		py-${DISTNAME:L}

CATEGORIES =		textproc devel

HOMEPAGE =		https://pypi.python.org/pypi/Unidecode

# GPLv2+
PERMIT_PACKAGE =	Yes

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes
MODPY_PYTEST =		Yes

FLAVORS =		python3
FLAVOR =		python3

.include <bsd.port.mk>
