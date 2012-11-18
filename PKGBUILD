# $Id: PKGBUILD 10863 2010-02-03 11:21:27Z spupykin $
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Dag Odenhall <dag.odenhall@gmail.com>
# Contributor: Grigorios Bouzakis <grbzks@gmail.com>
# Customized by: mjheagle <mjheagle8@gmail.com>

pkgname=dwm
pkgver=$(git hist | wc -l)
pkgrel=1
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

    make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11 || return 1
    make PREFIX=/usr/local DESTDIR=$pkgdir install || return 1

    install -m644 -D LICENSE $pkgdir/usr/local/share/licenses/$pkgname/LICENSE
    install -m644 -D README $pkgdir/usr/local/share/doc/$pkgname/README
    install -m755 -D startdwm $pkgdir/usr/local/bin/startdwm
    install -m755 -D killdwm $pkgdir/usr/local/bin/killdwm
    install -m755 -D mygtkmenu/buildgtkmenu.sh $pkgdir/usr/local/bin/buildgtkmenu.sh
}
