# $OpenBSD: Makefile,v 1.23 2021/12/27 00:14:52 afresh1 Exp $

COMMENT =	parse and format strp and strf time patterns

MODULES =	cpan
PKG_ARCH =	*
DISTNAME =	DateTime-Format-Strptime-1.79
EPOCH =		0
CATEGORIES =	devel

MAINTAINER =	Andrew Hewus Fresh <afresh1@openbsd.org>

# Artistic 2.0
PERMIT_PACKAGE =	Yes

RUN_DEPENDS =	devel/p5-DateTime>=1.0 \
		devel/p5-DateTime-Locale>=1.30 \
		devel/p5-DateTime-TimeZone>=2.09 \
		devel/p5-Params-ValidationCompiler \
		devel/p5-Specio>=0.33 \
		devel/p5-Try-Tiny

TEST_DEPENDS =	devel/p5-Test-Fatal \
		devel/p5-Test-Warnings

.include <bsd.port.mk>
