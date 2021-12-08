-- Jhennifer Rodrigues, 14A --

statistics :: String -> IO ()

statistics entrada = print ([primeiro, '.', ultimo], tamanho)
  where
      primeiro = head entrada
      ultimo = last entrada
      tamanho = length entrada
