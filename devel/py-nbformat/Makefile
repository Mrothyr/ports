# $OpenBSD: Makefile,v 1.15 2021/11/02 00:00:51 sthen Exp $

COMMENT =		Jupyter notebook format

MODPY_EGG_VERSION =	5.0.7
DISTNAME =		nbformat-${MODPY_EGG_VERSION}
PKGNAME =		py-${DISTNAME}
REVISION =		0

CATEGORIES =		devel

HOMEPAGE =		https://jupyter.org

RUN_DEPENDS =		devel/py-ipython_genutils${MODPY_FLAVOR} \
			devel/py-traitlets${MODPY_FLAVOR}>=4.1 \
			devel/py-jupyter_core${MODPY_FLAVOR} \
			devel/py-jsonschema${MODPY_FLAVOR}>=2.4
TEST_DEPENDS =		devel/py-testpath${MODPY_FLAVOR}

# BSD
PERMIT_PACKAGE =	Yes

MODULES =		lang/python
MODPY_PI =		Yes
MODPY_PYTEST =		Yes
MODPY_PYTEST_ARGS =	nbformat

FLAVORS =		python3
FLAVOR =		python3

.include <bsd.port.mk>
