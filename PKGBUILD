# $Id: PKGBUILD 10863 2010-02-03 11:21:27Z spupykin $
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Dag Odenhall <dag.odenhall@gmail.com>
# Contributor: Grigorios Bouzakis <grbzks@gmail.com>
# Customized by: mjheagle <mjheagle8@gmail.com>

pkgname=dwm
pkgver=5.7.2
pkgrel=2
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('i686' 'x86_64')
license=('MIT')
options=(zipman)
depends=('libx11')
install=dwm.install
source=()
md5sums=()

build() {
    cd $startdir
    pwd

    make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11 || return 1
    make PREFIX=/usr/local DESTDIR=$pkgdir install || return 1

    install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE && \
    install -m644 -D README $pkgdir/usr/share/doc/$pkgname/README
}
