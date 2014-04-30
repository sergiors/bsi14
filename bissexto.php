#!/usr/bin/env php
<?php
echo 'Digite um ano:';

$handle = fopen('php://stdin', 'r');
$year = trim(fgets($handle));

if (($year % 4 == 0) && ($year % 100 != 0) || ($year % 400 == 0)) {
  echo "O ano {$year} é bissexto", PHP_EOL;
} else {
  echo "O ano {$year} não é bissexto", PHP_EOL;
}
