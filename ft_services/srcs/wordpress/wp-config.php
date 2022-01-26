<?php
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'felisabe' );

/** MySQL database password */
define( 'DB_PASSWORD', 'felisabe' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql-service:3306' );
define( 'WP_HOME', 'http://192.168.99.121:5050' );
define( 'WP_SITEURL', 'http://192.168.99.121:5050' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

define( 'CONCATENATE_SCRIPTS', false );

/** Authentication Unique Keys and Salts. */
define('AUTH_KEY',         'f2,v+5HIz5d+d`BvA[)2+Z,~R95a#;I6Ekq7rj,@z2e$.|+8R.+.mX<bamO>WQ69');
define('SECURE_AUTH_KEY',  '}(:mMDiHmTYtVtLL8T|qct+s0]m|Yg1]m&&ng(;FzSAP_(?m_+uH8D)q$6U|i|@}');
define('LOGGED_IN_KEY',    'q-9WFZ2U6IF[Cg(n7{3/k;B]yawOk.<(cX`,v%s(e9e0f?&*u`GoTrOr4_-k/ix(');
define('NONCE_KEY',        'g-}Xm+^D2=oHV#)DN68_;98*kU7C4-hv<;C-$tl{-( u5e|v!gtKqGT;HJz;):Go');
define('AUTH_SALT',        'n|OsL}INBrd2-%5Q3A6Dx)#-.P;YO4+M=O>$V?7A##}MX.|Ei |&$p_:}MMb: :f');
define('SECURE_AUTH_SALT', 'QU9b=a+FdOl`  -:L~j-X+M}S5(nW~me7C7G y0.lc)lL/w>l[(tO80^1NfaJrr;');
define('LOGGED_IN_SALT',   '}8/3/HE%z8|VP5Vd|M2s*{SpT-wZODEA=x[{1dl7_]j9<($$N+yOh05GGxy6)#Hj');
define('NONCE_SALT',       '<:bB(H6yKe_g !2`Oab%vdgxu+EWSA-ImYoKG?4uPyQc+WZ-YutKXnaA2Q&+APPx');

/** WordPress Database Table prefix. */
$table_prefix = 'wp_';

/** For developers: WordPress debugging mode. */
define( 'WP_DEBUG', true );

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
