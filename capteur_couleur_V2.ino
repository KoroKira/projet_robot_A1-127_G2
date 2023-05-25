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
  if (rouge > 138  and rouge < 150  and vert > 85  and vert < 95 and bleu > 75 and bleu < 85 ) { return "bois"; }
  else if (165 < rouge and rouge < 175 and 85 < vert and vert < 100 and 75 < bleu and bleu < 90 ) { return "orange"; }
  else if (190 < rouge and rouge < 205 and 140 < vert and vert < 155 and 150 < bleu and bleu < 160 ) { return "violet"; }
  else if (205 < rouge and rouge < 220 and 135 < vert and vert < 150 and 140 < bleu and bleu < 160 ) { return "rose"; }
  else if (145 < rouge and rouge < 155 and 145 < vert and vert < 155 and 125 < bleu and bleu < 135 ) { return "vert"; }
  else if (145 < rouge and rouge < 160 and 90 < vert and vert < 105 and 55 < bleu and bleu < 70 ) { return "jaune"; }
  else if (145 < rouge and rouge < 155 and 120 < vert and vert < 135 and 135 < bleu and bleu < 145 ) { return "bleu"; }
  else if (190 < rouge and rouge < 205 and 175 < vert and vert < 190 and 80 < bleu and bleu < 95 ) { return "rouge"; }
  else if (110 < rouge and rouge < 120 and 80 < vert and vert < 90 and 65 < bleu and bleu < 75) { return "noir"; }
  else if (110 < rouge and rouge < 120 and 69 < vert and vert < 75 and 80 < bleu and bleu < 85) { return "blanc"; }
  else { return "Erreur"; }
  
}
