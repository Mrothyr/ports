# $OpenBSD: Makefile,v 1.22 2021/11/02 00:01:03 sthen Exp $

COMMENT =		test utilities working with files and commands

MODPY_EGG_VERSION =	0.4.2
DISTNAME =		testpath-${MODPY_EGG_VERSION}
PKGNAME =		py-${DISTNAME}
REVISION =		6

CATEGORIES =		devel

HOMEPAGE =		https://github.com/jupyter/testpath

# MIT
PERMIT_PACKAGE =	Yes

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes
MODPY_PYTEST =		Yes

FLAVORS =		python3
FLAVOR =	python3

BUILD_DEPENDS =		textproc/py-sphinx,python3>=4.0.2

.if !${FLAVOR:Mpython3}
RUN_DEPENDS =		devel/py-pathlib
.endif

post-build:
	cd ${WRKSRC}/doc && PYTHONPATH=${WRKSRC} \
	    ${LOCALBASE}/bin/sphinx-build -N . _build/html

DOCDIR = ${PREFIX}/share/doc/${MODPY_PY_PREFIX}testpath
post-install:
	cp -r ${WRKBUILD}/doc/_build/html ${DOCDIR}
	rm ${DOCDIR}/.buildinfo
	chown -R ${SHAREOWN}:${SHAREGRP} ${DOCDIR}

.include <bsd.port.mk>
