# $OpenBSD: Makefile,v 1.55 2021/09/02 12:55:44 sthen Exp $

COMMENT =		modules to parse and extract information from HTML

MODULES =		cpan
DISTNAME =		HTML-Parser-3.76
CATEGORIES =		www

RUN_DEPENDS =		www/p5-HTML-Tagset>=3
BUILD_DEPENDS =		${RUN_DEPENDS}
TEST_DEPENDS =		www/p5-URI \
			www/p5-libwww

# Perl
PERMIT_PACKAGE =	Yes

WANTLIB += c perl

MAKE_ENV +=		TEST_POD=Yes

.include <bsd.port.mk>
