void CapteurCouleur(float *rouge, float *vert, float *bleu){
  tcs.setInterrupt(false);  // turn on LED
  delay(60);  // takes 50ms to read
  tcs.getRGB(&*rouge, &*vert, &*bleu);
  tcs.setInterrupt(true);  // turn off LED
  /*
  Serial.print("R:\t"); Serial.print(int(*rouge)); 
  Serial.print("\tG:\t"); Serial.print(int(*vert)); 
  Serial.print("\tB:\t"); Serial.print(int(*bleu));
  */
  }

String Couleur(float rouge, float vert, float bleu) {
  //Cette fonction renvoie la couleur perçue par le capteur de couleur d'aprèse des tests faits en aval
  if (205 < rouge and rouge < 220 and 135 < vert and vert < 150 and 140 < bleu and bleu < 160 ) { return "rose"; }
  else if (145 < rouge and rouge < 155 and 145 < vert and vert < 155 and 125 < bleu and bleu < 135 ) { return "vert"; }
  else if (145 < rouge and rouge < 155 and 120 < vert and vert < 135 and 135 < bleu and bleu < 145 ) { return "bleu"; }
  else if (190 < rouge and rouge < 205 and 175 < vert and vert < 190 and 80 < bleu and bleu < 95 ) { return "rouge"; }
  else { return "Erreur"; }
  
}
