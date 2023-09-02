class Weapon:
    def __init__(self, damage, energy, resources):
        self.damage = damage
        self.energy = energy
        self.remaining_uses = resources

    def get_damage(self):
        if self.remaining_uses > 0:
            self.remaining_uses -= 1
            return self.damage
        else:
            print("No more uses left for this weapon!")
            return 0

class GruWeapon(Weapon):
    pass

class VectorWeapon(Weapon):
    pass

class FreezeGun(GruWeapon):
    def __init__(self):
        super().__init__(damage=11, energy=50, resources=float('inf'))

class ElectricProd(GruWeapon):
    def __init__(self):
        super().__init__(damage=18, energy=88, resources=5)

class MegaMagnet(GruWeapon):
    def __init__(self):
        super().__init__(damage=10, energy=92, resources=3)
        self.save = 0.2

class KalmanMissile(GruWeapon):
    def __init__(self):
        super().__init__(damage=20, energy=120, resources=1)

class LaserBlasters(VectorWeapon):
    def __init__(self):
        super().__init__(damage=8, energy=40, resources=float('inf'))

class PlasmaGrenades(VectorWeapon):
    def __init__(self):
        super().__init__(damage=13, energy=56, resources=8)

class SonicResonanceCannon(VectorWeapon):
    def __init__(self):
        super().__init__(damage=22, energy=100, resources=3)
