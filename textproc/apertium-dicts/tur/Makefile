# $OpenBSD: Makefile,v 1.5 2021/11/15 09:03:10 bentley Exp $

L =	tur
LANG =	Turkish
V =	0.2.0
REVISION =	0

BROKEN =	0.2.0 incompatible with apertium>=3.7.2

EXTRACT_SUFX =	.tar.bz2

BUILD_DEPENDS +=	textproc/hfst \
			textproc/vislcg3

USE_GMAKE =	Yes

AUTOCONF_VERSION =	2.71
AUTOMAKE_VERSION =	1.16

CONFIGURE_STYLE =	autoreconf

.include <bsd.port.mk>
