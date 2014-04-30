#!/usr/bin/env ruby

puts 'Digite um ano:'
year = gets.to_i

if year % 4 == 0 && year % 100 != 0 || year % 400 == 0
  puts "O ano #{year} é bissexto"
else
  puts "O ano #{year} não é bissexto"
end
