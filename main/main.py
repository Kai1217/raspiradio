import spotipy
from spotipy.oauth2 import SpotifyOAuth

sp = spotipy.Spotify(auth_manager = SpotifyOAuth(client_id="3220e0820f814df0a9a4af5d0ed259d6", client_secret="4c8158a659084abb95c6f98b3e2e2e69", redirect_uri="kaimatolat.xyz", scope="user-library-read"))

results = sp.current_user_saved_tracks()
for idx, item in enumerate(results['items']):
    track = item['track']
    print(idx, track['artists'][0]['name'], " - ", track['name'])
