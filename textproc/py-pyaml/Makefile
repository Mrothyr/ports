# $OpenBSD: Makefile,v 1.7 2021/11/19 09:01:49 sthen Exp $

COMMENT =		module to produce pretty and readable YAML

MODPY_EGG_VERSION =	21.10.1

DISTNAME =		pyaml-${MODPY_EGG_VERSION}
PKGNAME =		py-${DISTNAME}

CATEGORIES =		textproc

HOMEPAGE =		https://github.com/mk-fg/pretty-yaml

# WTFPL
PERMIT_PACKAGE =	Yes

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes
MODPY_PYTEST =		Yes
MODPY_PYTEST_ARGS =	pyaml/tests

FLAVORS =		python3
FLAVOR =		python3

TEST_DEPENDS =		textproc/py-unidecode${MODPY_FLAVOR}

.include <bsd.port.mk>
