# $OpenBSD: Makefile,v 1.10 2021/11/02 00:02:23 sthen Exp $

COMMENT =	library and tools to access the VMware Virtual Disk format

VERSION = 	20191221
DISTNAME =	libvmdk-alpha-${VERSION}
PKGNAME =	${DISTNAME:S/-alpha//}
REVISION =	1

SHARED_LIBS +=  vmdk                       0.0 # 1.0

CATEGORIES =	sysutils security

HOMEPAGE =	https://github.com/libyal/libvmdk/wiki

MASTER_SITES =	https://github.com/libyal/libvmdk/releases/download/${VERSION}/

MAINTAINER =	Remi Pointel <rpointel@openbsd.org>

# LGPLv3+
PERMIT_PACKAGE =	Yes

WANTLIB =  ${MODPY_WANTLIB}
WANTLIB += bfio c fuse iconv intl m pthread util z

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS +=	--enable-python3

WRKDIST =	${WRKDIR}/${PKGNAME}

MODULES +=	lang/python

BUILD_DEPENDS =	devel/gettext,-tools

LIB_DEPENDS +=	devel/libbfio

TEST_DEPENDS +=	shells/bash

pre-test:
	sed -i s,#!/bin/bash,#!/${LOCALBASE}/bin/bash, ${WRKSRC}/tests/test_*.sh

.include <bsd.port.mk>
