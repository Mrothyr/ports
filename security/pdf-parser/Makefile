# $OpenBSD: Makefile,v 1.15 2021/11/02 00:02:16 sthen Exp $

COMMENT =	parse a PDF document

MODPY_EGG_VERSION =	0.7.5
DISTNAME =	pdf-parser_V${MODPY_EGG_VERSION:S/./_/g}
PKGNAME =	pdf-parser-${MODPY_EGG_VERSION}
REVISION =	0

CATEGORIES =	security

HOMEPAGE =	http://blog.didierstevens.com/programs/pdf-tools/

MAINTAINER =	Remi Pointel <rpointel@openbsd.org>

# public domain
PERMIT_PACKAGE =	Yes

MASTER_SITES =	https://didierstevens.com/files/software/

EXTRACT_SUFX =	.zip

MODULES =	lang/python
RUN_DEPENDS =	security/yara/python${MODPY_FLAVOR}

NO_BUILD =	Yes
NO_TEST =	Yes

WRKDIST =	${WRKDIR}

MODPY_ADJ_FILES = pdf-parser.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pdf-parser.py ${PREFIX}/bin/pdf-parser

.include <bsd.port.mk>
